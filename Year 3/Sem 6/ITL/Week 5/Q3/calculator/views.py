from django.shortcuts import render

# Create your views here.

from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, "input.html")


def calculate(request):

    num1 = request.POST['num1']
    num2 = request.POST['num2']
    option = request.POST['dropdown'] 

    print("option :", option)

    if num1.isdigit() and num2.isdigit():
        a = int(num1)
        b = int(num2)
    else:
        res = "Only digits are allowed"
        return render(request, "input.html", {"result": res})

    if option == '+': res = a + b
    elif option == '-': res = a - b
    elif option == '*': res = a * b
    elif option == '/': res = a / b
    else: res = "Invalid Option"

    return render(request, "input.html", {"result": res})