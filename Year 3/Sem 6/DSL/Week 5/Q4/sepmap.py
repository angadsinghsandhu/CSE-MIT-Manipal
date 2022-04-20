import sys

def read_input(file):
    for line in file:
        yield line.strip().split(',')

def main(separator="\t"):
    data = read_input(sys.stdin)
    for words in data:
        for word in words:
            print("%s%s%d"%(word, separator, 1))

if __name__ == '__main__':
    sep = sys.argv[1]
    main(separator=sep)
