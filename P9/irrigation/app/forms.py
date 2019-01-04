# forms.py

from wtforms import Form, StringField, SelectField, TextField, PasswordField, IntegerField, validators
  
class RuleSearchForm(Form):
    choices = [('name', 'Name'),
               ('expression', 'Expression')]
    select = SelectField('Search for rule:', choices=choices)
    search = StringField('')

class RuleForm(Form):

    name = StringField('Name')
    expression = StringField('Expression')

