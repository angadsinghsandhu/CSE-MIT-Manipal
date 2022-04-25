from django import forms
from . import models


class EmpForm(forms.ModelForm):
    class Meta:
        model = models.EmpModel
        exclude = ()
