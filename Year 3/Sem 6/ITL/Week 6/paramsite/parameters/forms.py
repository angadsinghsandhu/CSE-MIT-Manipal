from django import forms

choices = [
    ('Hyundai', 'Hyundai'),
    ('Toyota', 'Toyota'),
    ('Honda', 'Honda'),
]

class CarForm(forms.Form):
    manufacturer = forms.ChoiceField(label="Car Manufacturer", choices=choices)
    model_name = forms.CharField(label="Model Name")