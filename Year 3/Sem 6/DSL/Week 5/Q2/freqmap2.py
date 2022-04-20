import sys

for line in sys.stdin:
    word, count = line.strip().split('\t', 1)
    count = int(count)
    print("{}\t{}".format(word, count))