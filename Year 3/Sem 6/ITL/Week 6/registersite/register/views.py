from django.http import HttpRequest, HttpResponseRedirect
from django.shortcuts import render

from .forms import RegisterForm

# Create your views here.
def register(request: HttpRequest):
    if request.method == 'POST':
        rf = RegisterForm(request.POST)
        if rf.is_valid():
            context = {
                'username': rf.cleaned_data['username'],
                'emailid': rf.cleaned_data['emailid'],
                'contactno': rf.cleaned_data['contactno'],
            }

            request.session['context'] = context
            return HttpResponseRedirect('/success/')
    rf = RegisterForm()
    return render(request, 'register/register.html', {'form': rf})

def success(request: HttpRequest):
    if request.session.has_key('context'):
        return render(request, 'register/success.html', {'context': request.session['context']})
    return render(request, 'register/success.html', {})
