import numpy as np

i = np.array([[1, 2], [4, 5]])
j = np.array([[1, 2], [4, 5]])
print(i.reshape(4, 1))
print(np.vstack((i, j)))
print(np.hstack((i, j)))


