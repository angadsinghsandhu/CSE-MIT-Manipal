from django.contrib import admin
from sites.models import CategoryModel, PageModel


# Register your models here.
class CategoryAdmin(admin.ModelAdmin):
    list_display = ('index', 'name',)
admin.site.register(CategoryModel, CategoryAdmin)

class PageAdmin(admin.ModelAdmin):
    list_display = ('index', 'category', 'title',)
admin.site.register(PageModel, PageAdmin)
