import sys

for line in sys.stdin:
    L = [ (word.strip().lower(), 1) for word in line.strip().split(',') ]

    for word, n in L:
        print("{}\t{}".format(word, n))