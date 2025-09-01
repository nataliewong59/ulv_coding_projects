# cards/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.BoxListView.as_view(), name='box-list'),
    path('box/new/', views.BoxCreateView.as_view(), name='box-create'),
    path('box/<int:pk>/', views.StudyView.as_view(), name='box-study'),
    path('cards/', views.AllCardsView.as_view(), name='card-list'),
    path('cards/new/', views.CardCreateView.as_view(), name='card-create'),
    path('cards/<int:pk>/edit/', views.CardUpdateView.as_view(), name='card-update'),
    path('box/<int:pk>/delete/', views.BoxDeleteView.as_view(), name='box-delete'),
    path('boxes/', views.BoxListView.as_view(), name='box-list'),

]
