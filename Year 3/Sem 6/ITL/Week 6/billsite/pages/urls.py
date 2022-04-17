from django.urls import path
from . import views

urlpatterns = [
    path('choose/', views.choose, name='choose'),
    path('total/', views.total, name='total'),
]