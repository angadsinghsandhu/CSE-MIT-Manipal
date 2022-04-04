from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, "input.html")


def stu_det(request):
    # details
    details = {
        'name': request.POST['name'],
        'dob': request.POST['dob'],
        'address': request.POST['address'],
        'contact': request.POST['contact'],
        'email': request.POST['email'],
    }

    # percentage marks
    num1 = request.POST['eng']
    num2 = request.POST['phy']
    num3 = request.POST['chem']

    if num1.isdigit() and num2.isdigit() and num3.isdigit():
        a = int(num1)
        b = int(num2)
        c = int(num3)
        num = str((a + b +c)/3)
        if len(num) > 5:
            num = (num)[:4]
        res = float(num)

        return render(request, "result.html", {"result": res, "details": details})
    else:
        res = "Only digits are allowed"
        return render(request, "result.html", {"result": res, "details": details})

