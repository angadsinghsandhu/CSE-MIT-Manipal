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

def clean(path, line):
    word = line.strip().split(",")

    if path == "../data/covid_19_data.csv":
        word = word[3].strip().strip("\"").strip("(").strip("\'")
    elif path == "../data/example.txt":
        word = word[3]
    elif path == "../data/german_credit.csv":
        word = word[2]
    elif path == "../data/heart_disease_data.csv":
        word = word[0]
    else:
        word = None

    return word

fd = open(path_in, "r")
wd = open(path_out, "w")
data = []

for line in fd:
    word = clean(path_in, line)

    if word is not None:
        data.append("{}\t{}".format(word, 1))

data.sort()

for line in data:
    wd.write(line + "\n")