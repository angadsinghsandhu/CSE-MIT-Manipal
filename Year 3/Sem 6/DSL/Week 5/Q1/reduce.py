from operator import itemgetter
import sys

# cd into current directory

## choose output path
path = "./covid_19_data_map.txt"
# path = "./example_map.txt"
# path = "./german_credit_map.txt"
# path = "./heart_disease_data_map.txt"

fd = open(path, "r")

current_word = None
current_count = 0
word = None

for line in fd:
    word, count = line.strip().split("\t", 1)

    try:
        count = int(count)
    except ValueError:
        print("Value Error Occured...")
        continue

    if current_word == word:
        current_count += count
    else:
        if current_word:
            print("{}\t{}".format(current_word, current_count))

        current_count = count
        current_word = word
    
if current_word == word:
    print("{}\t{}".format(current_word, current_count))