from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render

from emp.forms import EmpForm
from emp.models import EmpModel

# Create your views here.
def index(req):
    emps = EmpModel.objects.all()
    return render(req, 'emp.html', {'emps': emps, 'form': EmpForm()})

def add(req):
    if req.method == 'POST':
        form = EmpForm(req.POST)
   
        if form.is_valid():
            obj = form.save(commit=False)
            obj.save()

    return HttpResponseRedirect('/')

def get(req):
    if req.method == 'POST':
        company = req.POST['company']
   
        if company:
            emps = EmpModel.objects.filter(company=company)
            return render(req, 'filter.html', {'emps': emps})

    return HttpResponse("<h1>Incorrect Response</h1>")
