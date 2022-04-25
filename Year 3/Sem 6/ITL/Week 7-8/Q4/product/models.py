from django.db import models

# Create your models here.
class ProductModel(models.Model):
    title = models.CharField(max_length=100)
    price = models.PositiveIntegerField()
    des = models.CharField(max_length=1000)

    # class Meta:
    #     ordering = ("",)
