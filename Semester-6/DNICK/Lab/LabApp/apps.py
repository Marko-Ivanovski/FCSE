from django.apps import AppConfig


class LabappConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'LabApp'

    def ready(self):
        from . import signals
