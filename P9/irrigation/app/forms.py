# forms.py

from wtforms import Form, StringField, SelectField, TextField, PasswordField, IntegerField, validators
  
class RuleSearchForm(Form):
    choices = [('name', 'Name'),
               ('expression', 'Expression')]
    select = SelectField('Search for rule:', choices=choices)
    search = StringField('')

class ActionSearchForm(Form):
    choices = [('name', 'Name'),
               ('expression', 'Expression')]
    select = SelectField('Search for action:', choices=choices)
    search = StringField('')

class EventSearchForm(Form):
    choices = [('name', 'Name')]
    select = SelectField('Search for action:', choices=choices)
    search = StringField('')

class RuleForm(Form):

    name = StringField('Name', [validators.Length(min=1)])
    expression = StringField('Expression', [validators.Length(min=1)])

class ActionForm(Form):

    name = StringField('Name', [validators.Length(min=1)])
    expression = StringField('Expression', [validators.Length(min=1)])

class EventForm(Form):

    name = StringField('Name', [validators.Length(min=1)])
    rule = StringField('Rule', [validators.Length(min=1)])
    action = StringField('Action', [validators.Length(min=1)])