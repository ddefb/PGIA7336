from flask import Blueprint, render_template, request

bp = Blueprint(__name__, __name__,
                        template_folder='templates')

@bp.route('/rules', methods=['POST', 'GET'])
def show():
    if request.method == 'POST':
        # return str(request.form.get('rule'))
        if request.form.get('rule'):
            return 'Clicked'
    return render_template('rule_form.html')