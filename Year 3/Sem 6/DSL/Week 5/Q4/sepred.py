sh = '''
echo "Time is gold Time is Time gold" | python3 sepmap.py | python3 sepred.py
'''

import sys
from itertools import groupby
from operator import itemgetter

def read_mapper_output(file, separator='\t'):
    for line in file:
        return line.rstrip().split(separator, 1)

separator = '\t'

data = read_mapper_output(sys.stdin, separator=separator)

for current_word, group in groupby(data, itemgetter(0)):
    try:
        pass
    except ValueError:
        pass



