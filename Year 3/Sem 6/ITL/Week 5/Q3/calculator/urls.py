
from django.urls import path

from . import views     # it means - 'from all import views'

urlpatterns = [
    path('',views.index, name='index'),
    path('calc',views.calculate, name='calc'),
]

# whenever 'localhost:8000' will be called, function named 'index' will be called that is present in 'views.py' file
# This will happen for all other routes as well