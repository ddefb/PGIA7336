from flask import Blueprint, render_template

bp = Blueprint(__name__, __name__,
                        template_folder='templates')

@bp.route('/actions')
def show():
    return render_template('action_form.html')