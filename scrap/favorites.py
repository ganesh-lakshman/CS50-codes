import csv

file = open("Team Kanyarasi (Responses) - Form Responses 1.csv", "r")

counts = dict()
#counts = {}
reader = csv.DictReader(file)

for row in reader:
#    print(row["Email Address"])
#    counts[row["Email Address"]] = 1
 #   if counts[row["Email Address"]] != 1:
  #      counts[row["Email Address"]] += 1

    title = row["Email Address"].lower()
    if title in counts:
        counts[title] += 1
    else:
        counts[title] = 1
#print(counts)
#def fun(index):
 #   return index[1]
#for mails, num in sorted(counts.items(), key=fun, reverse=True):
for mails, num in sorted(counts.items(), key=lambda item: item[1], reverse=True):
    print(mails, num, sep=' | ' )


