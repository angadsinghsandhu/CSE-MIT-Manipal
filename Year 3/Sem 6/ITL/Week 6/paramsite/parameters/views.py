from django.shortcuts import render
from django.http import HttpRequest, HttpResponse

from .forms import CarForm

# Create your views here.
def index(request: HttpRequest):
    form = CarForm()
    return render(request, 'parameters/index.html', {'form':form})


def newpage(request):
    if request.method == 'POST':
        form = CarForm(request.POST)
        if form.is_valid():
            context = {
                'manufacturer': form.cleaned_data['manufacturer'],
                'model_name': form.cleaned_data['model_name'],
            }
            return render(request, 'parameters/newpage.html', context)
    return HttpResponse("Invalid Parameters")