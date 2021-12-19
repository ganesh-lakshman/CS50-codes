from cs50 import get_string

letters = 0
words = 0
sentences = 0

text = get_string("Text: ")

for i in range(len(text)):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letters += 1
    if text[i] == ' ':
        words += 1
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1

words = words + 1
l = (letters / words) * 100
s = (sentences / words) * 100

index = 0.0588 * l - 0.296 * s - 15.8
ind = int(round(index))
if ind > 16:
    print("Grade 16+")
if ind < 1:
    print("Before Grade 1")
elif ind >= 1 and ind <= 16:
    print("Grade", ind)