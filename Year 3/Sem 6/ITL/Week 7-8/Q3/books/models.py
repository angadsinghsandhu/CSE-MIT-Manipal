from pyexpat import model
from django.db import models

## Create your models here.

# author table
class AuthorModel(models.Model):
    fname = models.CharField(max_length=50)
    lname = models.CharField(max_length=50)
    email = models.EmailField()

    class Meta:
        ordering = ("fname",)

# publisher model
class PublisherModel(models.Model):
    name = models.CharField(max_length=100)
    street = models.CharField(max_length=20)
    city = models.CharField(max_length=20)
    state = models.CharField(max_length=20)
    country = models.CharField(max_length=20)
    url = models.URLField()

    class Meta:
        ordering = ("name",)


# book
class BookModel(models.Model):
    title = models.CharField(max_length=100)
    date = models.DateField()
    authors = models.ForeignKey(AuthorModel, on_delete=models.CASCADE)
    publisher = models.OneToOneField(PublisherModel, on_delete = models.CASCADE)

    class Meta:
        ordering = ("title",)