from django.contrib import admin
from . import models

# Register your models here.
class AuthorAdmin(admin.ModelAdmin):
    list_display = ('fname', 'lname', 'email')
admin.site.register(models.AuthorModel, AuthorAdmin)

class PublisherAdmin(admin.ModelAdmin):
    list_display = ('name', 'url',)
admin.site.register(models.PublisherModel, PublisherAdmin)

class BookAdmin(admin.ModelAdmin):
    list_display = ('title', 'authors', 'publisher')
admin.site.register(models.BookModel, BookAdmin)