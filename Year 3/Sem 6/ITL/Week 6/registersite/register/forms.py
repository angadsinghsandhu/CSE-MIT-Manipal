from django import forms

class RegisterForm(forms.Form):
    username = forms.CharField(label="UserName")
    password = forms.CharField(label="Password", widget=forms.PasswordInput, required=False)
    emailid = forms.EmailField(label="Email ID", required=False)
    contactno = forms.CharField(label="Contact No", max_length=10, required=False)