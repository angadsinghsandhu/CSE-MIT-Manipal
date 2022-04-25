from operator import mod
from django import forms
from . import models

class CategoryForm(forms.ModelForm):
    class Meta:
        model = models.CategoryModel
        exclude = ('index',)

class PageForm(forms.ModelForm):
    class Meta:
        model = models.PageModel
        exclude = ('index',)