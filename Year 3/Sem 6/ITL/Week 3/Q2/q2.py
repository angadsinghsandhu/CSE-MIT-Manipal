p1 = "./f1.txt"
p2 = "./f2.txt"

with open(p1) as f1:
    word = f1.read()

word = word[::-1]

with open(p2, 'w') as f2:
    f2.write(word)

print("The file has been written...")