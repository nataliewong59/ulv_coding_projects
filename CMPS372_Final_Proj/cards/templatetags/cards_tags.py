# cards/templatetags/cards_tags.py

from django import template
from django.utils.safestring import mark_safe
from cards.models import Box

register = template.Library()

@register.simple_tag
def boxes_as_links():
    boxes = Box.objects.all()
    links = [f'<a href="/box/{box.pk}/">{box.name}</a>' for box in boxes]
    return mark_safe(' '.join(links))  # ✅ this tells Django it's safe to render as HTML
