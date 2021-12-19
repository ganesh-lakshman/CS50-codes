#from cs50 import get_string

#s = get_string("whats ur name \n")
#print(f"hello, {s}")
from cs50 import get_string
#in python strings are not just charcter array, but structs which has functions (methods)like .lower()
c = get_string("do you agree\n")
#if c  == 'Y' or c == 'y':
if c.lower() in ["y", "yes"]:
    print("agreed")
#elif c == 'N' or c == 'n':
elif c.lower() in ["n", "no"]:
    print("not agreed")
#print("cough \n" * 3)
#for i in [0, 0, 0 ,1, 65, 0]:
#def cough():
 #   print("cough")

def main():
    for i in range(6):
        cough()
def cough():
    print("cough")
main()


def cough1():
    cough2(3)
def cough2(n):
    for i in range(n):
        print("cc")
cough1()

