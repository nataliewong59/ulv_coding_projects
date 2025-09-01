from django.urls import reverse_lazy
from django.views.generic import (
    ListView,
    CreateView,
    UpdateView,
    TemplateView
)
from django.views import View
from django.shortcuts import get_object_or_404, redirect, render
import json
import random

from .models import Card, Box
from .forms import BoxForm

from django.views.generic import TemplateView

class LandingPageView(TemplateView):
    template_name = 'cards/index.html'

# 📘 Show all boxes on homepage
class BoxListView(ListView):
    model = Box
    template_name = 'cards/box_list.html'

# ➕ Create a new box
class BoxCreateView(CreateView):
    model = Box
    form_class = BoxForm
    template_name = 'cards/box_form.html'

    def get_success_url(self):
        return reverse_lazy('box-study', kwargs={'pk': self.object.pk})


# 🎯 Study one box in random-card mode
class StudyView(View):
    template_name = 'cards/box.html'

    def get(self, request, pk):
        box = get_object_or_404(Box, pk=pk)
        cards = list(box.cards.all())
        context = {
            "box": box,
            "box_id": box.pk,
            "box_name": box.name,
            "cards_json": json.dumps([
                {"id": card.id, "question": card.question, "answer": card.answer}
                for card in cards
            ])
        }
        return render(request, self.template_name, context)

# 🗂 View all cards grouped by box
class AllCardsView(TemplateView):
    template_name = 'cards/card_list.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['boxes'] = Box.objects.prefetch_related('cards').all()
        return context

# 🔧 Generic views to create/edit cards
class CardListView(ListView):
    model = Card
    queryset = Card.objects.all()

class CardCreateView(CreateView):
    model = Card
    fields = ["question", "answer", "box"]
    template_name = "cards/card_form.html"
    
    def get_initial(self):
        initial = super().get_initial()
        box_id = self.request.GET.get("box")
        if box_id:
            initial["box"] = box_id
        return initial

    def get_success_url(self):
        return reverse_lazy("box-study", kwargs={"pk": self.object.box.pk})


class CardUpdateView(CardCreateView, UpdateView):
    success_url = reverse_lazy("card-list")

from django.views.generic import DeleteView

class BoxDeleteView(DeleteView):
    model = Box
    template_name = 'cards/box_confirm_delete.html'
    success_url = reverse_lazy('box-list')
