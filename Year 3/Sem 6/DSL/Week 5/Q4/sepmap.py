import sys

def read_input(file):
    for line in file:
        return line.split()

separator = "\t"

data = read_input(sys.stdin)

for words in data:
    for word in words:
        print("{}{}{}".format(word, separator, 1))