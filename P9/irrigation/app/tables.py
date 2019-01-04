from flask_table import Table, Col, LinkCol
 
class RulesTable(Table):
    id = Col('id', show=False)
    name = Col('name')
    expression = Col('expression')
    edit = LinkCol('Edit', 'edit_rule', url_kwargs=dict(id='id'), anchor_attrs={'class': "btn btn-primary btn-xs", })
    delete = LinkCol('Delete', 'delete_rule', url_kwargs=dict(id='id'), anchor_attrs={'class': "btn btn-danger btn-xs", })