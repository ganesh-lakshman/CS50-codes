#for i in range(4):
 #   print("#",end = "")
#print()
#print("#\n" * 3,end = "")
#for i in range(3):
  #  for j in range(3):
 #       print("#", end = "")
#    print()
#from time import sleep
#i = 1
#while True:

  # print(i)
 #   i*=2
#    sleep(0.01)
scores = []
scores.append(72)
scores.append(73)
scores.append(33)

print(f"average: {sum(scores)/len(scores)}")
from cs50 import get_string

s = get_string("i :")
print("o:", end = "")
#for i in range(len(s)):
 #   print(s[i], end = "")
for c in s:
    print(c,end = "")

print()
print(s.upper())
names = ["emma", "batman"]
if "emma" in names:
    print("found")
    exit(0)
print("nf")
exit(1)