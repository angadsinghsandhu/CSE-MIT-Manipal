
from . import views
from django.urls import path


urlpatterns = [
    path('', views.archive, name='archive'),
    path('create/', views.create, name='create'),
]