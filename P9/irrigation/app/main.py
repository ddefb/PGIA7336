import os
from app import app
from db_setup import init_db, db_session
from forms import RuleForm, RuleSearchForm
from flask import flash, render_template, request, redirect
from models import Rules
from tables import RulesTable

init_db()
  
@app.route('/')
def home():
	return render_template('home.html')

@app.route('/actions', methods=['GET', 'POST'])
def actions():
  actions = arep.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
  return render_template('actions.html', actions = actions.get_all_actions_as_list())

@app.route('/rules', methods=['POST', 'GET'])
def rules():
	search = RuleSearchForm(request.form)
	# print request.method
	# if request.method == 'POST':
	return search_results(search)
	# return render_template('rules.html', form=search)

@app.route('/events', methods=['GET', 'POST'])
def events():
  
  rules = rrep.RulesRepository("postgres", "osboxes.org", "localhost", "teste")
  actions = arep.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
  events = erep.EventsRepository("postgres", "osboxes.org", "localhost", "teste")

  events_list = [[e[0], rules.get_rule(e[1]), actions.get_action(e[2])] for e in events.get_all_events_as_list()]

  print events_list

  return render_template('events.html', events = events_list)

@app.route('/about')
def about():
  return render_template('about.html')
 
@app.route('/results')
def search_results(search):
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
		return render_template('rule_list.html', table=table)

@app.route('/rules_404')
def rules_404():
	return render_template('rules_404.html')

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
        	add_rule(form, new=True)
        	flash('Rule created successfully!')
        	return redirect('/rules')

    return render_template('rule_add.html', form=form)

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

@app.route('/edit/<int:id>', methods=['GET', 'POST'])
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

        return render_template('rule_edit.html', form=form)
    else:
        return 'Error loading #{id}'.format(id=id)


@app.route('/delete/<int:id>', methods=['GET', 'POST'])
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

        return render_template('rule_delete.html', form=form)
    else:
        return 'Error deleting #{id}'.format(id=id)
 
if __name__ == '__main__':
	app.run(debug=True)