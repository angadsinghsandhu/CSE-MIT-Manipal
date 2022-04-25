from sqlite3 import Timestamp
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from datetime import datetime
from blog.forms import BlogPostForm
from blog.models import BlogPost

# Create your views here.
def archive(req):
    posts = BlogPost.objects.all()
    return render(req, 'archive.html', {'posts': posts, 'form': BlogPostForm()})

def create(req):
    if req.method == "POST":
        form = BlogPostForm(req.POST)
        if form.is_valid():
            post = form.save(commit=False)
            post.timestamp = Timestamp.now()
            post.save()
    return HttpResponseRedirect("/")
