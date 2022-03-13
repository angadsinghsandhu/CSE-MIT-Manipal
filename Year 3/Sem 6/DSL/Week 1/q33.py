import numpy as np
x = [9,41,12,3,74,15]
y= np.zeros(len(x))
for i in range(len(x)):
    if x[i] > 20:
        y[i] = x[i]
print(y)