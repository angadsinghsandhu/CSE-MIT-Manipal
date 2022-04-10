from __future__ import print_function
import sys

# cd into current directory

## choose output path
path = "./covid_19_data_map.txt"
# path = "./example_map.txt"
# path = "./german_credit_map.txt"
# path = "./heart_disease_data_map.txt"

fd = open(path, "r")

mostFreq = []
currentMax = -1

for line in fd:
    word, count = line.strip().split('\t', 1)
    count = int(count)

    if count > currentMax:
        currentMax = count
        mostFreq = [ word ]

    elif count == currentMax:
        mostFreq.append(word)

for word in mostFreq:
    print("{}\t{}".format(word, currentMax))