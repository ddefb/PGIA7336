from flask import Flask, render_template, request
from flask_sqlalchemy import SQLAlchemy

import sys
sys.path.insert(0, './database')

# import rules_repository as rrep
# import actions_repository as arep
# import events_repository as erep

# @app.route('/')
# def home():
#   return render_template('home.html')

# @app.route('/actions', methods=['GET', 'POST'])
# def actions():
#   actions = arep.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
#   return render_template('actions.html', actions = actions.get_all_actions_as_list())

# @app.route('/rules', methods=['POST', 'GET'])
# def rules():
#   rules = rrep.RulesRepository("postgres", "osboxes.org", "localhost", "teste")
  
#   return render_template('rules.html', rules = rules.get_all_rules_as_list())

# @app.route('/delete_rule')
# def delete_rule():
#   rules = rrep.RulesRepository("postgres", "osboxes.org", "localhost", "teste")

#   return render_template('rules.html', rules = rules.get_all_rules_as_list())



# @app.route('/events', methods=['GET', 'POST'])
# def events():
  
#   rules = rrep.RulesRepository("postgres", "osboxes.org", "localhost", "teste")
#   actions = arep.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
#   events = erep.EventsRepository("postgres", "osboxes.org", "localhost", "teste")

#   events_list = [[e[0], rules.get_rule(e[1]), actions.get_action(e[2])] for e in events.get_all_events_as_list()]

#   print events_list

#   return render_template('events.html', events = events_list)

# @app.route('/about')
# def about():
#   return render_template('about.html')


# if __name__ == '__main__':
#   app.run(debug=True)
