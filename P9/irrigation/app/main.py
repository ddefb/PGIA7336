import os
from app import app
from db_setup import init_db, db_session
from forms import RuleForm, ActionForm, EventForm, RuleSearchForm, ActionSearchForm, EventSearchForm
from flask import flash, render_template, request, redirect
from models import Rules, Actions, Events
from tables import RulesTable, ActionsTable, EventsTable
from sqlalchemy.exc import IntegrityError

init_db()
  
@app.route('/')
def home():
    return render_template('home.html')

@app.route('/actions', methods=['GET', 'POST'])
def actions():
    search = ActionSearchForm(request.form)
    return search_actions(search)
    # return render_template('actions/actions.html')
    #   
    # # print request.method
    # # if request.method == 'POST':
    #   
    # # return render_template('rules.html', form=search)
    # # actions = arep.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
  

@app.route('/rules', methods=['POST', 'GET'])
def rules():
    search = RuleSearchForm(request.form)
    # print request.method
    # if request.method == 'POST':
    return search_rules(search)
    # return render_template('rules.html', form=search)

@app.route('/events', methods=['GET', 'POST'])
def events():
    search = EventSearchForm(request.form)
    return search_events(search)

@app.route('/about')
def about():
    return render_template('about.html')
 
@app.route('/rule_add', methods=['GET', 'POST'])
def new_rule():
    """
    Add a new rule
    """
    form = RuleForm(request.form)

    if request.method == 'POST':
        if "cancel" in request.form:
            return redirect('/rules')
        
        elif "submit" in request.form and form.validate():
            # save the rule
            try:
                add_rule(form, new=True)
                flash('Rule created successfully!')
                return redirect('/rules')
            
            except IntegrityError as error:
                if "duplicate key value" in str(error):
                    # flash('Rule created successfully!')
                    print "Rule alread exists!"


    return render_template('rules/rule_add.html', form=form)

def add_rule(form, new=False):
    """
    Save the changes to the database
    """
    name = form.name.data
    expression = form.expression.data
    rule = Rules(name, expression)
    print
    if new:
        # Add the new rule to the database
        db_session.add(rule)
    else:
        db_session.execute("update rules set expression=\'"+expression+"\' where name=\'"+str(rule.name)+"\';")
    # commit the data to the database
    db_session.commit()

@app.route('/rule_edit/<int:id>', methods=['GET', 'POST'])
def edit_rule(id):
    qry = db_session.query(Rules).filter(
                Rules.id==id)
    rule = qry.first()
 
    if rule:
        form = RuleForm(formdata=request.form, obj=rule)
        if request.method == 'POST':# and form.validate():
            if "cancel" in request.form:
                return redirect('/rules')
            # delete the item from the database
            elif "submit" in request.form and form.validate():
                add_rule(form)
                flash('Rule updated successfully!')
                return redirect('/rules')

        return render_template('rules/rule_edit.html', form=form)
    else:
        return 'Error loading #{id}'.format(id=id)


@app.route('/rule_delete/<int:id>', methods=['GET', 'POST'])
def delete_rule(id):
    """
    Delete the item in the database that matches the specified
    id in the URL
    """
    qry = db_session.query(Rules).filter(
        Rules.id==id)
    rule = qry.first()

    if rule:
        form = RuleForm(formdata=request.form, obj=rule)
        # if request.method == 'POST' and form.validate():
        if request.method == 'POST':
            if "cancel" in request.form:
                return redirect('/rules')
            # delete the item from the database
            elif "delete" in request.form:
                db_session.delete(rule)
                db_session.commit()
                flash('Rule deleted successfully!')
                return redirect('/rules')

        return render_template('rules/rule_delete.html', form=form)
    else:
        return 'Error deleting #{id}'.format(id=id)

@app.route('/list_rules')
def search_rules(search):
    results = []
    search_string = search.data['search']

    if search_string:
        if search.data['select'] == 'name':
            qry = db_session.query(Rules).filter(
                Rules.name.contains(search_string))
            results = qry.all()
        else:
            qry = db_session.query(Rules)
            results = qry.all()
    else:
        qry = db_session.query(Rules)
        results = qry.all()
    if not results:
        flash('No results found!')
        return redirect('/rules_404')
    else:
        # display results
        table = RulesTable(results)
        table.border = True
        return render_template('rules/rule_list.html', table=table)

@app.route('/rules_404')
def rules_404():
    return render_template('rules/rules_404.html')

@app.route('/action_add', methods=['GET', 'POST'])
def new_action():
    """
    Add a new action
    """
    form = ActionForm(request.form)

    if request.method == 'POST':
        if "cancel" in request.form:
            return redirect('/actions')
        
        elif "submit" in request.form and form.validate():
            # save the action
            try:
                add_action(form, new=True)
                flash('Action created successfully!')
                return redirect('/actions')
            
            except IntegrityError as error:
                if "duplicate key value" in str(error):
                    # flash('action created successfully!')
                    print "Action alread exists!"

    return render_template('actions/action_add.html', form=form)

def add_action(form, new=False):
    """
    Save the changes to the database
    """
    name = form.name.data
    expression = form.expression.data
    action = Actions(name, expression)
    print
    if new:
        # Add the new action to the database
        db_session.add(action)
    else:
        db_session.execute("update actions set expression=\'"+expression+"\' where name=\'"+str(action.name)+"\';")
    # commit the data to the database
    db_session.commit()

@app.route('/edit_action/<int:id>', methods=['GET', 'POST'])
def edit_action(id):
    qry = db_session.query(Actions).filter(
                Actions.id==id)
    action = qry.first()
 
    if action:
        form = ActionForm(formdata=request.form, obj=action)
        if request.method == 'POST':# and form.validate():
            if "cancel" in request.form:
                return redirect('/actions')
            # delete the item from the database
            elif "submit" in request.form and form.validate():
                add_action(form)
                flash('Action updated successfully!')
                return redirect('/actions')

        return render_template('actions/action_edit.html', form=form)
    else:
        return 'Error loading #{id}'.format(id=id)


@app.route('/delete_action/<int:id>', methods=['GET', 'POST'])
def delete_action(id):
    """
    Delete the item in the database that matches the specified
    id in the URL
    """
    qry = db_session.query(Actions).filter(
        Actions.id==id)
    action = qry.first()

    if action:
        form = ActionForm(formdata=request.form, obj=action)
        # if request.method == 'POST' and form.validate():
        if request.method == 'POST':
            if "cancel" in request.form:
                return redirect('/actions')
            # delete the item from the database
            elif "delete" in request.form:
                db_session.delete(action)
                db_session.commit()
                flash('action deleted successfully!')
                return redirect('/actions')

        return render_template('actions/action_delete.html', form=form)
    else:
        return 'Error deleting #{id}'.format(id=id)

@app.route('/list_actions')
def search_actions(search):
    results = []
    search_string = search.data['search']

    if search_string:
        if search.data['select'] == 'name':
            qry = db_session.query(Actions).filter(
                Actions.name.contains(search_string))
            results = qry.all()
        else:
            qry = db_session.query(Actions)
            results = qry.all()
    else:
        qry = db_session.query(Actions)
        results = qry.all()
    if not results:
        flash('No results found!')
        return redirect('/actions_404')
    else:
        # display results
        table = ActionsTable(results)
        table.border = True
        return render_template('actions/action_list.html', table=table)

@app.route('/actions_404')
def actions_404():
    return render_template('actions/actions_404.html')


@app.route('/event_add', methods=['GET', 'POST'])
def new_event():
    """
    Add a new rule
    """
    form = EventForm(request.form)

    if request.method == 'POST':
        if "cancel" in request.form:
            return redirect('/events')
        
        elif "submit" in request.form and form.validate():
            add_event(form, new=True)
            flash('Event created successfully!')
            return redirect('/events')
            
            # except IntegrityError as error:
            #     if "duplicate key value" in str(error):
            #         # flash('Rule created successfully!')
            #         print "Event alread exists!"


    return render_template('events/event_add.html', form=form)

def add_event(form, new=False):
    """
    Save the changes to the database
    """
    name = form.name.data
    rule = form.rule.data
    action = form.action.data

    event = Events(name, rule, action)
    event.name = name
    event.rules_id = rule
    event.actions_id = action

    if new:
        # Add the new rule to the database
        db_session.add(event)
    else:
        db_session.execute("update events set rules_id=\'"+rule+"\', actions_id=\'"+action+"\' where name=\'"+str(event.name)+"\';")
    # commit the data to the database
    db_session.commit()


@app.route('/list_events')
def search_events(search):
    results = []
    search_string = search.data['search']

    if search_string:
        if search.data['select'] == 'name':
            qry = db_session.query(Events).filter(
                Events.name.contains(search_string))
            results = qry.all()
        else:
            qry = db_session.query(Events)
            results = qry.all()
    else:
        qry = db_session.query(Events)
        results = qry.all()
    if not results:
        flash('No results found!')
        return redirect('/events_404')
    else:
        # display results
        table = EventsTable(results)
        table.border = True
        return render_template('events/event_list.html', results=results)

@app.route('/edit_event/<int:id>', methods=['GET', 'POST'])
def edit_event(id):
    qry = db_session.query(Events).filter(
                Events.id==id)
    event = qry.first()
 
    if event:
        form = EventForm(formdata=request.form, obj=event)
        if request.method == 'POST':# and form.validate():
            if "cancel" in request.form:
                return redirect('/events')
            # delete the item from the database
            elif "submit" in request.form and form.validate():
                add_action(form)
                flash('Event updated successfully!')
                return redirect('/events')

        return render_template('events/event_edit.html', form=form)
    else:
        return 'Error loading #{id}'.format(id=id)


@app.route('/delete_event/<int:id>', methods=['GET', 'POST'])
def delete_event(id):
    """
    Delete the item in the database that matches the specified
    id in the URL
    """
    qry = db_session.query(Events).filter(Events.id==id)
    event = qry.first()

    if event:
        form = EventForm(formdata=request.form, obj=event)
        # if request.method == 'POST' and form.validate():
        if request.method == 'POST':
            if "cancel" in request.form:
                return redirect('/events')
            # delete the item from the database
            elif "delete" in request.form:
                db_session.delete(event)
                db_session.commit()
                flash('event deleted successfully!')
                return redirect('/events')

        return render_template('events/event_delete.html', form=form)
    else:
        return 'Error deleting #{id}'.format(id=id)


@app.route('/events_404')
def events_404():
    return render_template('events/events_404.html')

@app.route('/run_controller')
def run_controller():
    events = db_session.query(Events).all()
    if events:
        os.system('make ept')
        # os.system('make')
        
    return render_template('home.html')

if __name__ == '__main__':
    app.run(debug=True)