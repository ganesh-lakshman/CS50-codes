import csv
from cs50 import get_string

#file = open("phonebook.csv", "a")

name = get_string("name: ")
number = get_string("number: ")

#variable writer to write stuff to file inside csv package library
#pass to writer function a file


with open("phonebook.csv","a") as file:

    writer = csv.writer(file)
    writer.writerow((name, number))

#file.close()





~/ $ python cs.py
name: ganesh
number: 9849656436
~/ $ python cs.py
name: suppu
number: none