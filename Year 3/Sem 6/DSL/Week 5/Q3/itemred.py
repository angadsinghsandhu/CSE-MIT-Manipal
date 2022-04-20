import fileinput

transaction_count = 0
sales_total = 0

for line in fileinput.input():

    try:
        data = line.strip().split("\t")
        if len(data) != 2:
            continue
    except ValueError:
        continue

    current_key, current_value = data
    try:
        sales_total += float(current_value)
        transaction_count += 1
    except ValueError:
        continue

print("{}\t{}".format(transaction_count, sales_total))