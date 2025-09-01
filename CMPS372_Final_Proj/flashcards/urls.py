"""flashcards URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
# flashcards/urls.py

from django.contrib import admin
from django.urls import path, include

from cards import views  
from cards.views import LandingPageView, AllCardsView

urlpatterns = [
     path('', LandingPageView.as_view(), name='index'),
     path('cards/', AllCardsView.as_view(), name='card-list'),
    path('admin/', admin.site.urls),
    path('', include('cards.urls')),
    path('', views.AllCardsView.as_view(), name='index'),
    path('box/new/', views.BoxCreateView.as_view(), name='box-create'),
    path('box/<int:pk>/', views.StudyView.as_view(), name='box-study'),  # replaces BoxView
]
