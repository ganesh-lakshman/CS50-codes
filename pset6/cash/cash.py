from cs50 import get_float

while True:
    dollars = get_float("enter the change: ")
    if dollars > 0:
        break

# c1 = 0, c5 = 0, c10 = 0, c25 = 0, TC = 0
c1, c5, c10, c25, TC = 0, 0, 0, 0, 0
cents = round(dollars * 100)
while cents >= 25:
    c25 += 1
    cents = cents - 25

while cents < 25 and cents >= 10:
    c10 += 1
    cents = cents - 10

while cents < 10 and cents >= 5:
    c5 += 1
    cents = cents - 5

while cents < 5 and cents >= 1:
    c1 += 1
    cents = cents - 1

print(c25 + c10 + c5 + c1)

