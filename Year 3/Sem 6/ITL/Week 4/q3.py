class Power:
    def __init__(self):
        pass

    def pow(self, x, n):
        return x**n;

x = 5
n = 2

# creating object
obj = Power()
print("the value of '%d' raised to the poer of '%d' is : '%d'" %(x, n, obj.pow(x, n)))
