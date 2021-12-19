from sys import exit
#dictionry keys and valuess
list = {
    "a": "9849656436",
    "b": "9959477331"
}
if "a" in list:
    print(f"{list['a']}")
    print("found")
    exit(0)
print("not found")
exit(1)