# echo "foo foo foo labs quux labs foo bar quux" | python3 freqmap1.py | sort | python3 freqred1.py | python3 freqmap2.py | sort | python3 freqred2.py

from __future__ import print_function
import sys

for line in sys.stdin:
    word, count = line.strip().split('\t', 1)
    count = int(count)
    print("{}\t{}".format(word, count))