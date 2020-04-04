import os
import time

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    user = db.execute("SELECT cash, username FROM users WHERE id=:id", id = session["user_id"])
    stocks = db.execute("SELECT shares, symbol FROM total WHERE username=:username", username=user[0]["username"])

    if not stocks:
        stocks = {'symbol': 'None', 'shares': 0, 'price': 0, 'sums': 0}
        return render_template("index.html", cash=user[0]["cash"], stocks=stocks)
    else:
        for stock in stocks:
            quote = lookup(stock['symbol'])
            if not quote:
                return apology("API not working!", 400)
            else:
                stock.update({'price': quote["price"]})
                sum = quote["price"] * stock['shares']
                stock.update({'sum': sum})

        amount = user[0]["cash"]
        for stock in stocks:
            amount += stock['sum']

        return render_template("index.html", stocks=stocks, amount=amount, company=quote["name"])

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must have a symbol!", 406)

        shares = request.form.get("shares")
        if not int(shares) > 0:
            return apology("At least 1 share :)", 406)

        quote = lookup(symbol)
        if not quote:
            return apology("We can't find that company", 406)

        totalPrice = int(shares) * quote["price"]

        user = db.execute("SELECT * FROM users WHERE id = :id",
                                    id=session["user_id"])
        userAmount = user[0]["cash"]
        username = user[0]["username"]
        
        if userAmount < totalPrice:
            return apology("Not enough money!", 406)
        
        localtime = time.localtime()
        hms = str(localtime[3]) + ":" + str(localtime[4]) + ":" + str(localtime[5])
        date = str(localtime[0]) + "-" + str(localtime[1]) + "-" + str(localtime[2])

        db.execute("INSERT INTO transactions (username, symbol, shares, price, time, date) VALUES (:username, :symbol, :shares, :price, :time, :date)",
                    username=username, symbol=quote["symbol"],
                    shares=shares, price=quote["price"], time=hms, date=date)
        userAmount -= totalPrice
        db.execute("UPDATE users SET cash=:userAmount WHERE id=:id", userAmount=userAmount, id=session["user_id"])

        row = db.execute("SELECT symbol FROM total WHERE symbol=:symbol AND username=:username", symbol=symbol, username=username)
        if not row:
            db.execute("INSERT INTO total (username, symbol, shares) VALUES (:username, :symbol, :shares)", username=username, symbol=symbol, shares=shares)
        else:
            preshares = db.execute("SELECT shares FROM total WHERE symbol=:symbol  AND username=:username", symbol=symbol, username=username)
            db.execute("UPDATE total SET shares=:totalshares WHERE symbol=:symbol AND username=:username", totalshare=preshares+shares, symbol=symbol, username=username)

        return redirect("/")

@app.route("/history")
@login_required
def history():
    user = db.execute("SELECT username FROM users WHERE id=:id", id=session["user_id"])
    transactions = db.execute("SELECT symbol, shares, price, date, time FROM transactions WHERE username=:username", username=user[0]["username"])

    if not transactions:
        return apology("NO history", 409)

    return render_template("history.html", transactions=transactions)



@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                            username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("You must provide a symbol!", 405)

        quote = lookup(symbol)

        if not quote:
            return apology("The stock doesn't exists!", 405)

        return render_template("quoted.html", name=quote["name"], symbol=quote["symbol"], price=quote["price"])


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        name = request.form.get("username")
        if not name:
            return apology("You must have a name!", 404)

        password = request.form.get("password")
        if not password:
            return apology("Please type in your password", 404)

        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("Please type in again!", 404)
        if not (confirmation == password):
            return apology("Passwords do not match!", 404)

        db.execute("INSERT INTO users (username, hash) VALUES (:name, :hashed)",
                    name = name, hashed = generate_password_hash(password))

        return redirect("/login")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method  == "GET":
        user = db.execute("SELECT username FROM users WHERE id=:id", id=session["user_id"])
        symbols = db.execute("SELECT symbol FROM total WHERE username=:username", username=user[0]["username"])

        if not symbols:
            return apology("Nothing to sell!", 407)
        
        return render_template("sell.html", symbols=symbols)
    else:
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Must provide a symbol", 408)

        user = db.execute("SELECT username, cash FROM users WHERE id=:id", id=session["user_id"])
        totalshares = db.execute("SELECT shares FROM total WHERE username=:username AND symbol=:symbol", username=user[0]["username"], symbol=symbol)

        shares = int(request.form.get("shares"))
        if not shares or shares <= 0:
            return apology("Provide a positive shares", 408)
        if shares > totalshares[0]["shares"]:
            return apology("You don't have that many shares", 408)

        price = lookup(symbol)["price"]

        localtime = time.localtime()
        hms = str(localtime[3]) + ":" + str(localtime[4]) + ":" + str(localtime[5])
        date = str(localtime[0]) + "-" + str(localtime[1]) + "-" + str(localtime[2])
        
        db.execute("INSERT INTO transactions (username, symbol, shares, price, time, date) VALUES (:username, :symbol, :shares, :price, :time, :date)", username=user[0]["username"], symbol=symbol, shares=-shares, price=price, time=hms, date=date)
        oldshares = db.execute("SELECT shares FROM total WHERE username=:username AND symbol=:symbol", username=user[0]["username"], symbol=symbol)
        db.execute("UPDATE total SET shares=:shares WHERE username=:username AND symbol=:symbol", shares=oldshares[0]["shares"]-shares, username=user[0]["username"], symbol=symbol)

        amountplus = shares * price
        print(amountplus)
        db.execute("UPDATE users SET cash=:cash WHERE id=:id", cash=user[0]["cash"]+amountplus, id=session["user_id"])

        return redirect("/")

def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
