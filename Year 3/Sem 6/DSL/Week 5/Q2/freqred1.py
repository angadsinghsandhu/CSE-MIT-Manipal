from __future__ import print_function
import sys

# cd into current directory

## choose output path
path = "./covid_19_data_map.txt"
# path = "./example_map.txt"
# path = "./german_credit_map.txt"
# path = "./heart_disease_data_map.txt"

fd = open(path, "r")

lastWord = None
sum = 0

for line in fd:
    word, count = line.strip().split('\t', 1)
    count = int(count)

    if lastWord == None:
        lastWord = word
        sum = count
        continue

    if word == lastWord:
        sum += count

    else:
        print("{}\t{}".format(lastWord, sum))
        sum = count
        lastWord = word

# output last word
if lastWord == word:
    print("{}\t{}".format(lastWord, sum))