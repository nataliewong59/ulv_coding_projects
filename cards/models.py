# cards/models.py

from django.db import models

NUM_BOXES = 5
BOXES = range(1, NUM_BOXES + 1)

class Box(models.Model):
    name = models.CharField(max_length=100)
    date_created = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.name

class Card(models.Model):
    question = models.CharField(max_length=100)
    answer = models.CharField(max_length=100)
    box = models.ForeignKey(Box, on_delete=models.CASCADE, related_name='cards')
    date_created = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.question


