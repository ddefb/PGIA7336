# db_creator.py
 
from sqlalchemy import create_engine, ForeignKey
from sqlalchemy import Column, Integer, String, Date
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship, backref

engine = create_engine('postgresql://diego:diego@localhost:5432/test', echo=True)
Base = declarative_base()

class Rules(Base):

    __tablename__ = "rules"

    id = Column(Integer, primary_key=True, autoincrement=True, unique=True)
    name = Column(String, nullable=False, unique=True)
    expression = Column(String, nullable=False, unique=True)

    def __init__(self, name, expression):
        """"""
        self.name = name
        self.expression = expression

    def __repr__(self):
        return "<Rules: {} {}>".format(self.name, self.expression)

class Actions(Base):

    __tablename__ = "actions"

    id = Column(Integer, primary_key=True, autoincrement=True, unique=True)
    name = Column(String, nullable=False, unique=True)
    expression = Column(String, nullable=False, unique=True)

    def __init__(self, name, expression):
        """"""
        self.name = name
        self.expression = expression

    def __repr__(self):
        return "<Actions: {} {}>".format(self.name, self.expression)

class Events(Base):
    """"""
    __tablename__ = "events"

    id = Column(Integer, primary_key=True, autoincrement=True, unique=True)
    name = Column(String, nullable=False, unique=True)
    
    rules_id = Column(Integer, ForeignKey("rules.id"), nullable=False, unique=True)
    rules = relationship("Rules", backref=backref("events", order_by=id))

    actions_id = Column(Integer, ForeignKey("actions.id"), nullable=False, unique=True)
    actions = relationship("Actions", backref=backref("events", order_by=id))

    def __init__(self, name, id_rule, id_action):
        """"""
        self.name = name
        self.id_rule = id_rule
        self.id_action = id_action

# create tables
Base.metadata.create_all(engine)