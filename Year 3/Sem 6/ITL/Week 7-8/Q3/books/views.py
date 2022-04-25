from django.http import HttpResponseRedirect
from django.shortcuts import render
from . import models, forms

# Create your views here.
def index(req):
    authors = models.AuthorModel.objects.all()
    publishers = models.PublisherModel.objects.all()
    books = models.BookModel.objects.all()

    return render(req, 'book.html', {'authors': authors, 
    'author_form': forms.AuthorForm(), 'publishers': publishers, 
    'publisher_form': forms.PublisherForm(), 'books': books, 
    'book_form': forms.BookForm()})

def create(req):
    if req.method == 'POST':
        author_form = forms.AuthorForm(req.POST)
        publisher_form = forms.PublisherForm(req.POST)
        book_form = forms.BookForm(req.POST)

        print("=== Reached Here ===")

        if author_form.is_valid() and publisher_form.is_valid() and book_form.is_valid():
            author = author_form.save(commit=False)
            publisher = publisher_form.save(commit=False)
            book = book_form.save(commit=False)
    
            author.save()
            publisher.save()
            book.save()
        else:
            print("ERROR")
            print("Authors Valid : ", author_form.is_valid())
            print("Publisher Valid : ", publisher_form.is_valid())
            print("Book Valid : ", book_form.is_valid())

        if not author_form.is_valid():
            return render(req, 'err.html', {'form': author_form})
        elif not publisher_form.is_valid():
            return render(req, 'err.html', {'form': publisher_form})
        elif not book_form.is_valid():
            return render(req, 'err.html', {'form': book_form})

    return HttpResponseRedirect('/')
