from flask import Flask, render_template, json
# from flask import request
from irrigation.views.index import bp as index_bp
from irrigation.views.rules import bp as rules_bp
from irrigation.views.actions import bp as actions_bp

app = Flask(__name__)
app.register_blueprint(index_bp)
app.register_blueprint(rules_bp)
app.register_blueprint(actions_bp)

if __name__ == '__main__':
	app.run(debug=True)

# @app.route('/signUp',methods=['POST'])
# def signUp():
#     # read the posted values from the UI
#     _rule_expression = request.form['input_rule_expression']
#     # validate the received values
#     if _name and _email and _password:
#         return json.dumps({'html':'<span>All fields good !!</span>'})
#     else:
#         return json.dumps({'html':'<span>Enter the required fields</span>'})