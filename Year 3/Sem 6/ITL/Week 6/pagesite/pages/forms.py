from django import forms

choices = [
    ('Math', 'Math'),
    ('English', 'English'),
    ('Physics', 'Physics'),
]

class FirstForm(forms.Form):
    name = forms.CharField(label="Name")
    roll = forms.CharField(label="Roll")
    subject = forms.ChoiceField(label="Subject", choices=choices)