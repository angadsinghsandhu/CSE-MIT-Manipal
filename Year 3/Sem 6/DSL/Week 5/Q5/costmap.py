import fileinput

for line in fileinput.input():
    data = line.strip().split(",")

    if len(data) == 3:
        credibility, creditamount, durationofcredit = data
        print("{}\t{}".format(credibility, creditamount))