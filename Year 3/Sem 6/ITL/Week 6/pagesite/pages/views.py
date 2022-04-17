from django.shortcuts import render
from django.http import HttpRequest, HttpResponseRedirect

from .forms import FirstForm

# Create your views here.
def firstpage(request: HttpRequest):
    context = {
        'name': None,
        'roll': None,
        'subject': None,
    }

    if request.method == 'POST':
        ff = FirstForm(request.POST)
        if ff.is_valid():
            context = {
                'name': ff.cleaned_data['name'],
                'roll': ff.cleaned_data['roll'],
                'subject': ff.cleaned_data['subject'],
            }
            request.session['context'] = context
            return HttpResponseRedirect('/secondpage/')
    
    ff = FirstForm()
    return render(request, 'pages/firstpage.html', {'form': ff})

def secondpage(request: HttpRequest):
    if request.method == 'POST':
        del request.session['context']
        return HttpResponseRedirect('/firstpage/')

    if request.session.has_key('context'):
        return render(request, 'pages/secondpage.html', {'context':request.session['context']})
    
    return render(request, 'pages/secondpage.html', {})
