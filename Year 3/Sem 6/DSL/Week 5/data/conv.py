path = "./example_test.txt"
path_out = "./example_out.csv"
import csv  

fd = open(path, "r")

data = []

for line in fd:
    lst = list(line.strip().split("\t"))
    data.append(lst)

print("data : ", data)

header = ['date', 'time', 'location', 'item type', 'amount', "card type"]

with open(path_out, 'w', encoding='UTF8') as f:
    writer = csv.writer(f)

    # write the header
    writer.writerow(header)

    # write the data
    for row in data:
        print("row : ", row)
        writer.writerow(row)