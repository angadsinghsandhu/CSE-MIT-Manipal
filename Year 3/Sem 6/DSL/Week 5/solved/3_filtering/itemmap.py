import fileinput

for line in fileinput.input():
    data = line.strip().split("\t")

    if len(data) == 6:
        date, time, location, item, cost, payment = data
        print("{}\t{}".formay(payment, cost))