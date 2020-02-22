from sys import argv, exit
import csv
import re

def main():
    if len(argv) != 3:
        print("Usage: python dna.py database sequence")
        exit(1)

    with open(argv[2], "r") as file:
        dna = file.read()

    with open(argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
    
        sq = reader.fieldnames
        
    sqnum = len(sq)
    mtchbook = {}

    for i in range(1, sqnum):
        mtchbook[sq[i]] = 0
        length = len(sq[i])
        for j in range(0, len(dna)):
            mtchnum = 0
            while dna[j:(j + len(sq[i]))] == sq[i]:
                mtchnum += 1
                j += len(sq[i])
            if mtchbook[sq[i]] < mtchnum:
                mtchbook[sq[i]] = mtchnum

    with open(argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for key, value in row.items():
                if value.isnumeric() == True:
                    strmtch = str(mtchbook[key])
                    if value == strmtch:
                        match = True
                    else:
                        match = False
                        break

            if match == True:
                print(row['name'])
                exit(0)

    print("No match")

main()


