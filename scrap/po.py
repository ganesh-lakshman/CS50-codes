from cs50 import get_int

def main():
    i = get_positive_int()
    print(i)

def get_positive_int():
    while True:
        n = get_int("positive inteer")
        if n > 0:
            break
    return n
main()
#in py variables are accessible outside the loops and conditions
#but variables arent available acrsss funs
