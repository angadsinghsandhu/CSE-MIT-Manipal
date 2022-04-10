sh = '''
cat home/dir/eample.txt | python3 costmap.py | sort | python3 costred.py
'''

import fileinput

max_val = 0
old_key = None

for line in fileinput.input():

    data = line.strip().split("\t")

    if len(data) != 2:
        continue

    current_key, current_value = data

    if old_key and (old_key != current_key):
        print("{}\t{}".format(old_key, max_val))
        old_key = current_key

        max_val = 0

    old_key = current_key
    if float(current_value) > float(max_val):
        max_val = float(current_value)

    if old_key != None:
        print("{}\t{}".format(old_key, max_val))