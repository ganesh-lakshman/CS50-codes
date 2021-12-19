from cs50 import get_int

while True:
    number = get_int("enter credit card number: ")
    if number > 0:
        break

j = 0
a = []
while number != 0:
    digits = number % 10
    number = number - digits
    number = number / 10
    a.append(int(digits))
    j += 1
p = j
# for i in range(len(a)):
#   print(a[i],end="")
k = 0
es = 0
es1 = 0
os = 0
for i in range(int(p / 2)):
    if a[2 * i + 1] > 4:
        l = 2 * a[2 * i + 1]
        while l > 0:
            x = l % 10
            k = k + x
            l = l - x
            l = l / 10

        es = es + k
        k = 0
    else:
        es1 = 2 * a[2 * i + 1] + es1

if p % 2 != 0:
    for z in range(int((p / 2) + 1)):
        os = os + a[2 * z]
else:
    for y in range(int(p / 2)):
        os = os + a[2 * y]
counter = 0
if (os + es + es1) % 10 == 0:
    if p == 15 and (a[14] == 3 and (a[13] == 4 or a[13] == 7)):
        print("AMEX")
        counter = 1
    if p == 16 and (a[15] == 5 and (a[13] <= 5)):
        print("MASTERCARD")
        counter = 1
    if (p == 13 and a[12] == 4) or (p == 16 and a[15] == 4):
        print("VISA")
        counter = 1
    if counter == 0:
        print("INVALID")
else:
    print("INVALID")