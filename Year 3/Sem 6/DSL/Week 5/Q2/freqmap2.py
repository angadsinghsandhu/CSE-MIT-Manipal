# echo "foo foo foo labs quux labs foo bar quux" | python3 freqmap1.py | sort | python3 freqred1.py | python3 freqmap2.py | sort | python3 freqred2.py

from __future__ import print_function
import sys

# cd into current directory

## choose output path
path = "./covid_19_data_map.txt"
# path = "./example_map.txt"
# path = "./german_credit_map.txt"
# path = "./heart_disease_data_map.txt"

fd = open(path, "a")

for line in fd:
    word, count = line.strip().split('\t', 1)
    count = int(count)
    line = "{}\t{}".format(word, count)
    fd.write(line + "\n")