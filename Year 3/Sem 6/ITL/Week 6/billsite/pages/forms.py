from django import forms

choices_company = [
    ('HP', 'HP'),
    ('Nokia', 'Nokia'),
    ('Samsung', 'Samsung'),
    ('Motorola', 'Motorola'),
    ('Apple', 'Apple'),
]

choices_item = [
    ('Mobile', 'Mobile'),
    ('Laptop', 'Laptop'),
]

class ChooseForm(forms.Form):
    company = forms.ChoiceField(label="Company", choices=choices_company, widget=forms.RadioSelect)
    item = forms.MultipleChoiceField(label="Item", choices=choices_item, widget=forms.CheckboxSelectMultiple)
    quantity = forms.IntegerField(label="Quantity")