from pyexpat import model
from django.db import models

# Create your models here.
class CategoryModel(models.Model):
    index = models.PositiveIntegerField()
    name = models.CharField(max_length=100)
    visits = models.PositiveIntegerField()
    likes = models.PositiveIntegerField()

    class Meta:
        ordering = ("index",)

class PageModel(models.Model):
    index = models.PositiveIntegerField()
    category = models.CharField(max_length=100)
    title = models.CharField(max_length=100)
    url = models.URLField()
    views = models.PositiveIntegerField()

    class Meta:
        ordering = ("index",)
