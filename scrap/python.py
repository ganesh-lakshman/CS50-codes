#print("hello, world")
import cs50
from cs50 import get_string
answer = get_string("whats your name\n")
print("hello, " +answer)
print("hello,",answer)
print("hello,", answer)
# print takes arguments it cancatinates automatically by adding a space
print(f"hello, {answer}")
#we have to include format string f string just like %s -> {}
counter = 0
counter += 1
x = 2
y = 3
if x < y:
    print("y is greter")
elif x > y:
    print("x is greater")
else:
    print("x and y are equal")
#while True:
  #  print("hello, world")
i = 3
#while i > 0:
#    print("cogh")
#    i -= 1
#for i in [50, 100, 500]:
#    print("cogh")
print(f"{i}")
#print("",i) wrong approach space includes
#print(""+i) wrong since noting to concatinate
for i in range(3):
    print("cough")

