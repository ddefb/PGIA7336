# app.py
from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://diego:diego@localhost:5432/test'
app.secret_key = "flask rocks!"

db = SQLAlchemy(app)