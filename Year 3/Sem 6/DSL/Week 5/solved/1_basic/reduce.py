# sh command : echo "a a a a hh cc cc hh vh jr"|python3 mapper.py|sort|python3 reduce.py
from operator import itemgetter
import sys

current_word = None
current_count = 0
word = None

for line in sys.stdin:
    line = line.strip()
    word, count = line.split("\t", 1)

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


