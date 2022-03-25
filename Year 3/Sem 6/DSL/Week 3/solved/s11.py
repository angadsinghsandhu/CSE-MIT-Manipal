import numpy as np

k = np.array([[1, 2], [4, 5]])
sum = 0

for i in range(k.shape[0]):
    for j in range(k.shape[0]):
        sum += k[i, j]
print(sum)



