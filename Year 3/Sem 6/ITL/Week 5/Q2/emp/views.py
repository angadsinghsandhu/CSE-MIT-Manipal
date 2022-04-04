from ntpath import join
from django.shortcuts import render
from datetime import date, datetime

# Create your views here.

def index(request):
    return render(request, "input.html")

def employee(request):

    join_date = request.POST['date']

    current_year = date.today().year
    joining_year = datetime.strptime(join_date, '%d/%m/%Y').year

    print("\n\n", current_year, joining_year, "\n\n")

    if (current_year - joining_year) > 5:

        return render(request, "input.html", {"result": "  Yes"})
    else:
        return render(request, "input.html", {"result": "  NO"})
