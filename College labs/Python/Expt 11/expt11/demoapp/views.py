from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def home1(request) :
    return render(request, 'demoapp/home.html')