words = set()

def check(word):
    #todo
    if word in words:
        return True
    else:
        return False
def load(dictionary):
    #todo
    file = open(dictionary, "r")
    for line in file:
        words.add(line.rstrip("\n"))
    file.close()
    return True
def size():
    #todo
    return len(words)
def unload():
    #todo
    return True
