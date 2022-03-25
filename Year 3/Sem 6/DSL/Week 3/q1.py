num = int(input("Enter a number : "))

print("\nFactors of " +str(num)+ " are: ")
for i in range(1, num+1):
    if num % i == 0:
        print(i,end =" ")
print()