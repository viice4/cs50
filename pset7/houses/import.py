from sys import argv, exit
import csv
import cs50

def main():
    if len(argv) != 2:
        print("Usage: python import.py csvfile")
        exit(1)

    db = cs50.SQL("sqlite:///students.db")

    with open (argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile, delimiter=",")

        for row in reader:
            name_cut(row)

            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                        row["f_name"], row["m_name"], row["l_name"], row["house"], row["birth"], )

def name_cut(row):
    name = row["name"]
    
    count = name.count(" ") + 1

    if count == 3:
        i = 0
        f_name = ""
        m_name = ""
        l_name = ""
        while name[i] != " ":
            f_name += name[i]
            i += 1
        row["f_name"] = f_name
        i += 1

        while name[i] != " ":
            m_name += name[i]
            i += 1
        row["m_name"] = m_name
        i += 1

        while i < len(name):
            l_name += name[i]
            i += 1
        row["l_name"] = l_name
    
    else:
        i = 0
        f_name = ""
        l_name = ""
        while name[i] != " ":
            f_name += name[i]
            i += 1
        row["f_name"] = f_name
        i += 1

        row["m_name"] = None

        while i < len(name):
            l_name += name[i]
            i += 1
        row["l_name"] = l_name

    del row["name"]

main()
