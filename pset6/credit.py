card = int(input("enter a credit card number: "))

dig1 = 0
dig2 = 0
sum1 = 0
sum2 = 0
cts = 0

while card > 0:
    dig2 = dig1
    dig1 = card % 10

    if (cts % 2) == 0:
        sum1 += dig1
    else:
        multi = dig1 * 2
        sum2 += int(multi / 10) + (multi % 10)
    card = int(card / 10)
    cts += 1

if_valid = (sum1 + sum2) % 10 == 0
fst_two = (dig1 * 10) + dig2

if cts == 15 and (fst_two == 34 or fst_two == 37) and if_valid:
    print("AMEX\n")
elif cts == 16 and fst_two >= 51 and fst_two <= 55 and if_valid:
    print("MASTERCARD\n")
elif cts >= 13 and cts <= 16 and dig1  == 4 and if_valid:
    print("VISA\n")
else:
    print("INVALID\n")
