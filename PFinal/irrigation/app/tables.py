from flask_table import Table, Col, LinkCol
 
class RulesTable(Table):
    id = Col('id', show=True, th_html_attrs={'class': 'id'})
    name = Col('name')
    expression = Col('expression')
    edit = LinkCol('edit', 'edit_rule', url_kwargs=dict(id='id'), anchor_attrs={'class': "btn btn-primary btn-xs",}, td_html_attrs={'class': 'edit'}, th_html_attrs={'class': 'edit'})
    delete = LinkCol('delete', 'delete_rule', url_kwargs=dict(id='id'), anchor_attrs={'class': "btn btn-danger btn-xs",}, td_html_attrs={'class': 'del'}, th_html_attrs={'class': 'del'})

class ActionsTable(Table):
    id = Col('id', show=True, th_html_attrs={'class': 'id'})
    name = Col('name')
    expression = Col('expression')
    edit = LinkCol('edit', 'edit_action', url_kwargs=dict(id='id'), anchor_attrs={'class': "btn btn-primary btn-xs",}, td_html_attrs={'class': 'edit'}, th_html_attrs={'class': 'edit'})
    delete = LinkCol('delete', 'delete_action', url_kwargs=dict(id='id'), anchor_attrs={'class': "btn btn-danger btn-xs",}, td_html_attrs={'class': 'del'}, th_html_attrs={'class': 'del'})

class EventsTable(Table):
    id = Col('id', show=True)
    name = Col('name')
    rule = Col('rule')
    action = Col('action')
    edit = LinkCol('edit', 'edit_event', url_kwargs=dict(id='id'))
    delete = LinkCol('delete', 'delete_event', url_kwargs=dict(id='id'))