sh = '''
echo '3' | python3 mappq.py | python3 redpi.py
'''

from __future__ import print_function
from operator import itemgetter

import sys

sum = 0

for line in sys.stdin:
    line = line.strip()
    
    word, count = line.split('\t', 1)

    try:
        count = float(count)
    except ValueError:
        continue

    sum += count

print("%1.10f\t0" %(sum))

