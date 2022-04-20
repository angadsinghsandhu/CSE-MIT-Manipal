from operator import itemgetter
import sys

current_word = None
current_count = 0
word = None

for line in sys.stdin:
    try:
        word, count = line.strip().split('\t', 1)
        count = int(count)
    except ValueError:
        continue

    if current_word == word:
        current_count += count
    else:
        if current_word:
            print("%s\t%d"%(current_word, current_count))
        
        current_count = count
        current_word = word
    
if current_word == word:
    print("%s\t%d"%(current_word, current_count))