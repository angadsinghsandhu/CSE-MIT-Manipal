import sys

for line in sys.stdin:
    words = line.strip().split()

    for word in words:
        num = int(word)
        if num % 2 == 0:
            print("%s\t%d"%("even", 1))
        else:
            print("%s\t%d"%("odd", 1))