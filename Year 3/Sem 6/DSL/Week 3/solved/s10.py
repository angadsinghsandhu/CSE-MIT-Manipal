import numpy as np

k = np.array([[1, 2], [4, 5]])
sum = 0

for i in k:
    for j in i:
        sum += j
print(sum)



