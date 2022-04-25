from django.db import models

# Create your models here.
class EmpModel(models.Model):
    name = models.CharField(max_length=100, primary_key=True)
    company = models.CharField(max_length=30)
    salary = models.PositiveIntegerField()
    street = models.CharField(max_length=30)
    city = models.CharField(max_length=30)

    class Meta:
        ordering = ('name',)
