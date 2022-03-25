
# calculator
while True:
    string = str(input("Enter The Equation (use +,-,*,/ and spacing) : "))
    eq = string.split()

    if len(eq) < 3:
        print("Wrong Input Try Again...\n")
        continue

    sign = eq[1]

    eq.remove(sign)
    eq = [ int(x) for x in eq ]

    if "+" in sign:
        sol = eq[0] + eq[1]
    elif "-" in sign:
        sol = eq[0] - eq[1]
    elif "*" in sign:
        sol = eq[0] * eq[1]
    elif "/" in sign:
        sol = eq[0] / eq[1]
    else:
        print("Wrong Input Try Again...\n")
        continue

    print("%s = %s\n" %(string, str(sol)))

