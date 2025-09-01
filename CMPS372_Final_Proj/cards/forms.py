from .models import Box
from django import forms

class BoxForm(forms.ModelForm):
    class Meta:
        model = Box
        fields = ['name']
