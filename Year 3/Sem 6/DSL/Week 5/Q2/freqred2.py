import sys

mostFreq = []
currentMax = -1

for line in sys.stdin:
    word, count = line.strip().split('\t', 1)
    count = int(count)

    if count > currentMax:
        currentMax = count
        mostFreq = [ word ]

    elif count == currentMax:
        mostFreq.append(word)

for word in mostFreq:
    print("{}\t{}".format(word, currentMax))