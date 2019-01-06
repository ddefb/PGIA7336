# forms.py

from wtforms import Form, StringField, SelectField, TextField, PasswordField, IntegerField, validators
from models import Rules, Actions, Events
from db_setup import init_db, db_session
from tables import ActionsTable

import sqlalchemy
from sqlalchemy import *
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

init_db()
  
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

    qry_rules = db_session.query(Rules).all()
    rules_list = [(r.id, r.name) for r in qry_rules]
    print rules_list

    qry_actions = db_session.query(Actions).all()
    actions_list = [(a.id, a.name) for a in qry_actions]

    name = StringField('Name', [validators.Length(min=1)])
    rule = SelectField('Rule', choices=rules_list, coerce=int)
    action = SelectField('Action', choices=actions_list, coerce=int)