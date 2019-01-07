from app import db

class Rules(db.Model):
    __tablename__ = "rules"

    id = db.Column(db.Integer, primary_key=True, autoincrement=True, unique=True)
    name = db.Column(db.String, nullable=False, unique=True)
    expression = db.Column(db.String, nullable=False, unique=True)

    def __init__(self, name, expression):
        """"""
        self.name = name
        self.expression = expression

    def __repr__(self):
        return "<Rules: {} {}>".format(self.name, self.expression) 

class Actions(db.Model):
    __tablename__ = "actions"

    id = db.Column(db.Integer, primary_key=True, autoincrement=True, unique=True)
    name = db.Column(db.String, nullable=False, unique=True)
    expression = db.Column(db.String, nullable=False, unique=True)

    def __init__(self, name, expression):
        """"""
        self.name = name
        self.expression = expression

    def __repr__(self):
        return "<Actions: {} {}>".format(self.name, self.expression) 

class Events(db.Model):
    """"""
    __tablename__ = "events"

    id = db.Column(db.Integer, primary_key=True, autoincrement=True, unique=True)
    name = db.Column(db.String, nullable=False, unique=True)    
    rules_id = db.Column(db.Integer, db.ForeignKey("rules.id"), nullable=False, unique=True)
    actions_id = db.Column(db.Integer, db.ForeignKey("actions.id"), nullable=False, unique=True)

    rules = db.relationship("Rules", backref=db.backref("events", order_by=id), lazy=True)
    actions = db.relationship("Actions", backref=db.backref("events", order_by=id), lazy=True)

    def __init__(self, name, id_rule, id_action):
        """"""
        self.name = name
        self.id_rule = id_rule
        self.id_action = id_action