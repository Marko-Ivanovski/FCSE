from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('flight/<int:flight_id>/', views.details, name='details'),  # Details for a single flight
    path('contact/', views.contact, name='contact'),  # Contact form page
    path('add/', views.add_flight, name='add_flight'),  # Add a new flight
    path('edit/<int:flight_id>/', views.edit_flight, name='edit_flight'),  # Edit a flight
]
