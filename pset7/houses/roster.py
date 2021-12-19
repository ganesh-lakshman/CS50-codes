# TODO
# reading data from db and presenting
# select * from students where house = "Gryffindor" order by last,first;
import sys
import cs50

if len(sys.argv) != 2:

    exit(1)
db = cs50.SQL("sqlite:///students.db")
housename = sys.argv[1]
reader = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last,first", housename)
for row in reader:
    if row['middle'] == None:
        print(f"{row['first']} {row['last']}, born {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")