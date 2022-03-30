class String:
    def __init__(self):
        self.word = ''

    def getString(self):
        self.word = str(input("Enter a String : "))

    def printString(self):
        print("The String in all caps is : ", self.word.upper())

# creating object
obj = String()
obj.getString()
obj.printString()
