import sys
import csv

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py file_data.csv file_sequence.txt")
        sys.exit(1)
    person = {}
    STRs = []
    STRrepetitions = []
    with open(sys.argv[1], "r") as datafile:
        reader = csv.reader(datafile)
        for row in reader:
            STRs = row[1 : ]
            break
        for row in reader:
            person[row[0]] = [int(x) for x in row[1 : ]]
    with open(sys.argv[2], "r") as sequencefile:
        sequence = sequencefile.read().strip()
    for STR in STRs:
        STR_maxrepetition = max_repetition(sequence, STR)
        STRrepetitions.append(STR_maxrepetition)
    find_dna(person, STRrepetitions)
def max_repetition(txt, key):
    i = 0
    j = i + len(key)
    maxi = 0
    for c in range(len(txt)):
        maxi_temp = 0
        if txt[i : j] == key:
            while txt[i : j] == key:
                maxi_temp += 1
                i += len(key)
                j += len(key)
                if maxi_temp > maxi:
                    maxi = maxi_temp
        else:
            i += 1
            j += 1
    return maxi
def find_dna(dictionary, array):
    values = dictionary.values()
    if array not in values:
        print("No match")
    else:
        for key, value in dictionary.items():
            if value == array:
                print(key)
main()