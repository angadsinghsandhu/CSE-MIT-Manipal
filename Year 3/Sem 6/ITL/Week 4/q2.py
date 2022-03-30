class Numbers:
    def __init__(self, arr, target):
        self.arr = arr
        self.target = target
        self.indexes = []
        self.findIndexes()

    def findIndexes(self):
        arrSet = set(self.arr)

        for i, v in enumerate(self.arr):
            if (self.target - v) in arrSet:
                self.indexes.append((i, self.arr.index(self.target - v)))

    def displayTargetElements(self):
        print("The Pair Array is : ", self.indexes)

array = [0, 10, 20, 30, 40, 50, 60, 70]
target = 50

# creating object
obj = Numbers(array, target)
obj.displayTargetElements()
