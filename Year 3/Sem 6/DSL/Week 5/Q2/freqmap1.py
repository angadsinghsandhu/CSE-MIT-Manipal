from __future__ import print_function
import sys

# cd into current directory

## choose dataset path
path_in = "../data/covid_19_data.csv"
# path_in = "../data/example.txt"
# path_in = "../data/german_credit.csv"
# path_in = "../data/heart_disease_data.csv"

## choose output path
path_out = "./covid_19_data_map.txt"
# path_out = "./example_map.txt"
# path_out = "./german_credit_map.txt"
# path_out = "./heart_disease_data_map.txt"

fd = open(path_in, "r")
wd = open(path_out, "w")
data = []

for line in fd:
    L = [ (word.strip().lower(), 1) for word in line.strip().split().split(",") ]

    for word, n in L:
        data.append("{}\t{}".format(word, n))

data.sort()

for line in data:
    wd.write(line + "\n")