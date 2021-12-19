from cs50 import get_int
while True:
    h = get_int("Height: ")
    if h < 9 and h > 0:
        break
n = 1
m = 1
for i in range(h):
    for k in range(h-1):
        print(" ", end="")
    for j in range(n):
        print("#", end="")
    print("  ", end="")
    for l in range(m):
        print("#", end="")
    print()
    h -= 1
    n += 1
    m += 1