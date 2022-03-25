import numpy as np

d = np.array([[1, 2], [4, 5]])
e = np.array([[1, 2], [4, 5]])
print(d - e)
print(d**2)
print(10 * np.sin(d))
print(e < 3)

f = np.array([[1, 2], [4, 5]])
g = np.array([[1, 2], [4, 5]])
print(f*g)
print(f.dot(g))
print(f.sum(axis=0))

h = np.array([[1, 2], [4, 5]])
print(h[1:2])
print(h[1][0])
print(h[0:1:2])
print(h[0:-1])