# TODO
# inserting data into studensts database
# check cmd line args
# open csv given by cmld line args
# for each row we have to sline in respective colums
# insert each stu in student databse
#


import sys
import csv
import cs50
if len(sys.argv) != 2:
    exit(1)
db = cs50.SQL("sqlite:///students.db")
# print(db)
csvfile = sys.argv[1]
# print(csvfile)
# db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC) ")
file = open(csvfile, "r")
reader = csv.DictReader(file)
for row in reader:
    # print(row)
    txt = row["name"]
    name = txt.split()
    if len(name) == 3:
        firstn = name[0]
        middlen = name[1]
        lastn = name[2]
    else:
        firstn = name[0]
        middlen = None
        lastn = name[1]
    housen = row["house"]
    birthn = row["birth"]
    db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", firstn, middlen, lastn, housen, birthn)