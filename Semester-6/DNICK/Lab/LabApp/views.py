from django.shortcuts import render, redirect, get_object_or_404

from .forms import *
from .models import Flight
from datetime import datetime

# Create your views here.

def index(request):
    flights = Flight.objects.filter(date__lte=datetime.now().date())
    context = {'flights_list': flights, 'app_name': 'FlightApp'}
    return render(request, 'index.html', context)\

def details(request, flight_id):
    flight = Flight.objects.filter(id=flight_id).first()
    context = {'flights_list': flight, 'app_name': 'FlightApp'}
    return render(request, 'details.html', context)

def contact(request):
    if request.method == "POST":
        form = ContactForm(request.POST)
        if form.is_valid():
            pass
        return redirect('index')

    form = ContactForm()
    return render(request, 'contact.html', context = {'form': form})

def add_flight(request):
    if request.method == "POST":
        form = FlightForm(request.POST, request.FILES1)
        if form.is_valid():
            form.save()
        return redirect('index')

    form = FlightForm()
    return render(request, 'add_flight.html', context = {'form': form})

def edit_flight(request, flight_id):
    flight = get_object_or_404(Flight, pk=flight_id)
    if request.method == "POST":
        form = FlightForm(request.POST, request.FILES, instance=flight)
        if form.is_valid():
            form.save()

        return redirect('index')

    form = FlightForm(instance=flight)
    return render(request, 'edit_flight.html', context = {'form': form})