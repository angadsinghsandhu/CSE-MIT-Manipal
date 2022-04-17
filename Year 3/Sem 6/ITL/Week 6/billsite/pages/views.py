from django.http import HttpRequest, HttpResponseRedirect
from django.shortcuts import render

from .forms import ChooseForm

mapping = {
    'HP': 1000,
    'Nokia': 2000,
    'Samsung': 3000,
    'Motorola': 4000,
    'Apple': 5000,
}

# Create your views here.
def choose(request: HttpRequest):
    cf = ChooseForm()
    return render(request, 'pages/choose.html', {'form': cf})

def total(request: HttpRequest):
    if request.method == 'POST':
        cf = ChooseForm(request.POST)
        total = 0
        if cf.is_valid():
            context = {
                'company': cf.cleaned_data['company'],
                'item': "",
            }
            total = mapping[context['company']]
            items = cf.cleaned_data.get("item")
            for item in items:
                total += 1000
                context['item'] += item + " "
            total *= cf.cleaned_data['quantity']
            context['total'] = total
            return render(request, 'pages/total.html', {'context': context})
            