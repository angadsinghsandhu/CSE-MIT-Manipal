lst = [12, -7, 38, -56, 78]
pos = neg = 0
for i in lst:
    if i < 0 : neg += 1
    else : pos += 1 

print("Num pos : %d, Num neg : %d" % (pos, neg))