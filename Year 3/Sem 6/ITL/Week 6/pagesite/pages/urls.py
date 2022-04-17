from django.urls import path
from . import views

urlpatterns = [
    path('firstpage/', views.firstpage, name='firstpage'),
    path('secondpage/', views.secondpage, name='secondpage'),
]