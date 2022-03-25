import numpy as np

# a
initialArray = ["1.1", "2.2", "3.3", "4.4"]
sampleArray = np.array(initialArray)
convertedArray = sampleArray.astype(np.float)
print("Our final array: ", str(convertedArray))
print("Final type: " + str(type(convertedArray[0])))

# b
tup = (11, 21, 19, 18, 46, 29)
arr = np.asarray(tup)
print(arr)

# c
b = np.zeros([3, 4], dtype = int)
print("\nMatrix b : \n", b)
print()

# d
for i in range(0,20,5):
    print(i, end=" ")
print()

# e
arr = np.ones([3, 4])
arr = arr[:, :, np.newaxis]
print(arr.shape)
new = np.reshape(arr, (2, 2, 3))
print(new.shape)

# f
lst = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

print("\nMAX : \n", lst.max())
print(lst.max(axis=0))
print(lst.max(axis=1))

print("\nMIN : \n", lst.min())
print(lst.min(axis=0))
print(lst.min(axis=1))

print("\nSUM : \n", lst.sum())
print(lst.sum(axis=0))
print(lst.sum(axis=1))

