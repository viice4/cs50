from sys import argv, exit
import cs50

def main():
    if len(argv) != 2:
        print("Usage: python roster.py housename")
        exit(1)

    db = cs50.SQL("sqlite:///students.db")
    
    list = db.execute("SELECT * FROM students")

    printbook = []
    
    for i in range(len(list)):
        if list[i]["house"] == argv[1]:
            printbook.append(list[i])

    newbook = sorted(printbook, key = lambda k: (k["last"], k["first"]))

    for i in range(len(newbook)):
        if newbook[i]["middle"] != None:
            print(newbook[i]["first"], newbook[i]["middle"], newbook[i]["last"] + ", born", newbook[i]["birth"])
        else:
            print(newbook[i]["first"], newbook[i]["last"] + ", born", newbook[i]["birth"])
        
main()
