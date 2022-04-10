sh = '''
cat home/dir | python3 itemmap.py | sort | python3 itemsep.py
'''


import fileinput

transaction_count = 0
sales_total = 0

for line in fileinput.input():

    data = line.strip().split("\t")

    if len(data) != 2:
        continue

    current_key, current_value = data

    transaction_count += 1
    sales_total += float(current_value)

print("{}\t{}".format(transaction_count, sales_total))