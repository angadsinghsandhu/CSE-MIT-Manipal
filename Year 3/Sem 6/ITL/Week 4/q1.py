import itertools

class Integers:
    def __init__(self, arr):
        self.arr = arr
        self.subsets = []
        self.findAllSubsets()

    def findNSubsets(self, s, n):
        return list(itertools.combinations(s, n))

    def findAllSubsets(self):
        size = len(self.arr)
        for i in range(0, size + 1):
            self.subsets.append(self.findNSubsets(self.arr, i))

    def displaySubsets(self):
        print("The Subset Array is : ", self.subsets)

array = [4, 5, 6]

# creating object
obj = Integers(array)
obj.displaySubsets()
