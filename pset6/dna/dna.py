# open csv file and dna sequence and read contents into memory and store in a ds
import sys
import csv
k = len(sys.argv)
if k != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(5)
# first argument databse second argument sequence
filedb = open(sys.argv[1], "r")
filesq = open(sys.argv[2], "r")
# print(filesq.read())

# csv_reader = csv.reader(filedb, delimiter=',')
# list ['name', 'AGATC', 'AATG', 'TATC'],['Alice', '2', '8', '3']...
# print(csv_reader)
# for row in csv_reader:
#    print(row)
#    print(f"{row[0]},{row[1]},{row[2]},{row[3]}")
# https://realpython.com/python-csv/

csv_dreader = csv.DictReader(filedb)

# print(csv_dreader)
# list of dicts list=[] dict = {}
# ordered dictinary
# dict with first row as keys [('name', 'Alice'), ('AGATC', '2'), ('AATG', '8'), ('TATC', '3')], ([('name', 'Bob'), ('AGATC', '4'), ('AATG', '1'), ('TATC', '5')]....
# https://www.geeksforgeeks.org/python-dictionary/?ref=lbp
# for drow in csv_dreader:
#    print(drow)
#   print(f'{drow["name"]},{drow["AGATC"]},{drow["AATG"]},{drow["TATC"]}')
# for str compute the repeats from the sequence and store in a ds
# for each posiion in seq compute how many times str reapeats starting at that position
# for each position keep checking succesive substrings untill no longer str repeatss
seq = filesq.read()
# print(seq)
n = len(seq)
counter1 = []
for i in range(n):
    counter1.append(0)
# for "AGATC" in seq:
for x in range(n):
    if seq[x:x+5] == "AGATC":
        counter1[x] += 1
#        if counter[x+5] == 1:
#           counter[x+5] += 1
# print(counter1)
for y in range(n):
    if counter1[y] > 0 and y + 5 < n:
        if counter1[y + 5] > 0:
            counter1[y + 5] = counter1[y] + counter1[y + 5]
# print(counter1)
# for AATG in seq
counter2 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter2.append(0)
for x in range(n):
    if seq[x:x+4] == "AATG":
        counter2[x] += 1
# print(counter2)
for y in range(n):
    if counter2[y] > 0 and y + 4 < n:
        if counter2[y + 4] > 0:
            counter2[y + 4] = counter2[y] + counter2[y + 4]
# print(counter2)
# for AATG in seq
counter3 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter3.append(0)
for x in range(n):
    if seq[x:x+4] == "TATC":
        counter3[x] += 1
# print(counter3)
for y in range(n):
    if counter3[y] > 0 and y + 4 < n:
        if counter3[y+4] > 0:
            counter3[y+4] = counter3[y] + counter3[y+4]
# print(counter3)
counter4 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter4.append(0)
for x in range(n):
    if seq[x:x+8] == "TTTTTTCT":
        counter4[x] += 1
# print(counter3)
for y in range(n):
    if counter4[y] > 0 and y + 8 < n:
        if counter4[y+8] > 0:
            counter4[y+8] = counter4[y] + counter4[y+8]
# print(counter3)

counter5 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter5.append(0)
for x in range(n):
    if seq[x:x+5] == "TCTAG":
        counter5[x] += 1
for y in range(n):
    if counter5[y] > 0 and y + 5 < n:
        if counter5[y+5] > 0:
            counter5[y+5] = counter5[y] + counter5[y+5]

counter6 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter6.append(0)
for x in range(n):
    if seq[x:x+4] == "GATA":
        counter6[x] += 1
for y in range(n):
    if counter6[y] > 0 and y + 4 < n:
        if counter6[y+4] > 0:
            counter6[y+4] = counter6[y] + counter6[y+4]

counter7 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter7.append(0)
for x in range(n):
    if seq[x:x+4] == "GAAA":
        counter7[x] += 1
for y in range(n):
    if counter7[y] > 0 and y + 4 < n:
        if counter7[y+4] > 0:
            counter7[y+4] = counter7[y] + counter7[y+4]

counter8 = []
i = 0
x = 0
y = 0
for i in range(n):
    counter8.append(0)
for x in range(n):
    if seq[x:x+4] == "TCTG":
        counter8[x] += 1
for y in range(n):
    if counter8[y] > 0 and y + 4 < n:
        if counter8[y+4] > 0:
            counter8[y+4] = counter8[y] + counter8[y+4]
# a list of all max values
list = []
# agatc
list.append(max(counter1))
# aatg
list.append(max(counter2))
# tatc
list.append(max(counter3))
# TTTTTTCT
list.append(max(counter4))
# TCTAG
list.append(max(counter5))
# GATA
list.append(max(counter6))
# GAAA
list.append(max(counter7))
# TCTG
list.append(max(counter8))


# compare str counts in csv
for drow1 in csv_dreader:
    #    print(drow)
    #    print(f'{drow1["name"]},{drow1["AGATC"]},{drow1["AATG"]},{drow1["TATC"]}')
    # name,AGATC,TTTTTTCT,AATG,TCTAG,GATA,TATC,GAAA,TCTG
    #    print(f'{drow1["name"]},{drow1["AGATC"]},{drow1["TTTTTTCT"]},{drow1["AATG"]},{drow1["TCTAG"]},{drow1["GATA"]},{drow1["TATC"]},{drow1["GAAA"]},{drow1["TCTG"]}')
    if sys.argv[1] == "databases/small.csv":

        if int(drow1["AGATC"]) == list[0] and int(drow1["AATG"]) == list[1] and int(drow1["TATC"]) == list[2]:
            print(f'{drow1["name"]}')
            exit(0)
    if sys.argv[1] == "databases/large.csv":

        if int(drow1["AGATC"]) == list[0] and int(drow1["TTTTTTCT"]) == list[3] and int(drow1["AATG"]) == list[1] and int(drow1["TCTAG"]) == list[4] and int(drow1["GATA"]) == list[5] and int(drow1["TATC"]) == list[2] and int(drow1["GAAA"]) == list[6] and int(drow1["TCTG"]) == list[7]:
            print(f'{drow1["name"]}')
            exit(1)

print("No match")
exit(2)