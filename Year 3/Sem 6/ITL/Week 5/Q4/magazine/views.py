from django.shortcuts import render

# Create your views here.
from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, "input.html")


def cover(request):

    data = {
        "text": request.POST['text'],
        "img": request.POST['img'],
        "bg_color": request.POST['bg_color'],
        "font_size": request.POST['font_size'],
        "text_color": request.POST['text_color'] ,

        "title":request.POST['title'] ,
        "title_size":request.POST['title_size'] ,
        "title_font":request.POST['title_font'],
    }

    return render(request, "output.html", data)