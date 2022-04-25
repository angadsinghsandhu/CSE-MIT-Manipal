import re
from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.shortcuts import render
from . import models, forms

# Create your views here.
def index(req):
    prods = models.ProductModel.objects.all()

    return render(req, 'prod.html', {'prods': prods})

def add(req):
    return render(req, 'add.html', {'prod_form': forms.ProductForm()})

def create(req):
    if req.method == 'POST':
        prod_form = forms.ProductForm(req.POST)

        print("=== Reached Here ===")

        if prod_form.is_valid():
            prod = prod_form.save(commit=False)
            prod.save()
        else:
            print("ERROR")

    return HttpResponseRedirect('/')
