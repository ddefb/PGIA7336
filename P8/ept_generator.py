#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Definindo as regras e as ações
# As listas deverão ser obtidas em consulta ao banco de dados.
# Assim, o usuário cadastra previamente as regras e as ações.
r = ['h_var < 30', 'h_var > 50 or h_var > 55', 't_var = 50']
a = ['device_bomb & device_valve', 'not device_bomb & not device_valve', 'device_bomb & not device_valve']

# Atribuindo um label para cada regra e cada ação
rules = {}
for i in range(len(r)):
	rules['R' + str(i)] = r[i]

actions = {}
for i in range(len(a)):
	actions['A' + str(i)] = a[i]

rule_name_expr = [[r_name, r_expr] for r_name, r_expr in rules.items()]
action_name_expr = [[a_name, a_expr] for a_name, a_expr in actions.items()]

# Criando os eventos, onde estão associadas cada uma das regras a uma ação.
# O usuário deve cadastrar os eventos fazendo associações entre as regras existentes e as ações que cadastrou previamente.
events = [[rule_name_expr[0][0], a[0]], [rule_name_expr[1][0], a[1]], [rule_name_expr[2][0], a[2]]]

# Verificando se cada regra foi associada a uma ação.
for i in range(len(rule_name_expr)):
	if not any(rule_name_expr[i][0] in e for e in events):
		raise Exception('An action was not defined for a rule.')

# Selecionando as variáveis de entrada e saída presentes nas regras e ações
inputs_var = list(set([s for s in filter (lambda x: 'var' in x, [item for item in r for item in item.split()])]))
outputs_var = list(set([s for s in filter (lambda x: 'device' in x, [item for item in a for item in item.split()])]))

# Inicia a criação do nodo threshold checker.
# Criando os tipos baseado na definição de cada regra. R0, R1, R2, ..., Rn.
modes_str = 'type modes = Initial | ' + " | ".join('%s'%s[0] for s in rule_name_expr) + '\n'
# Definindo os paramentros de entrada do nodo. Assume-se que ele deverá retornar apenas o tipo ao qual o estado está associado.
threshold_checker_str = 'node threshold_checker(' + ", ".join('%s'%s for s in inputs_var) + ':int) returns(mode: modes)\n' \
'let\n' \
'\tautomaton\n'
# Criando cada estado baseado nos R0, R1, R2, ..., Rn e suas respectivas condições de transição.
for i in range(len(rule_name_expr)):
	threshold_checker_str += '\t\tstate ' + rule_name_expr[i][0] + '_STATE' + ' do\n'
	threshold_checker_str += '\t\t\tmode = ' + rule_name_expr[i][0] + '\n'
	threshold_checker_str += '\t\t\tunless ' + ' | '.join('%r then %r_STATE' %(r[1], r[0]) for r in rule_name_expr if rule_name_expr.index(r) != i).replace('\'', '') + '\n'

threshold_checker_str += '\tend\n' \
'tel\n'

# Definindo o nodo device
device_str = 'node device(c: bool) returns (device_on:bool)\n' \
'let\n' \
'\tautomaton\n' \
'\t\tstate OFF do\n' \
'\t\t\tdevice_on = false;\n' \
'\t\t\tunless c then ON\n' \
'\t\tstate ON do\n' \
'\t\t\tdevice_on = true;\n' \
'\t\t\tunless not c then OFF\n' \
'\tend\n' \
'tel\n'

# Definindo o nodo messenger
messenger_str = 'node messenger(v:modes) returns (s:bool)\n' \
'var last x:modes = Initial;\n' \
'let\n' \
    '\tif v = last x\n'\
    '\tthen s = false\n'\
    '\telse x = v; s = true;\n'\
    '\tend\n'\
'tel\n'

# Definindo o nodo de controle
# Definindo as variáveis de entrada e saída
# Como entrada serão todas as variáveis definidas pelas regras
# Como saída estão todas as variáveis que representam as ações, além do nodo de Threshold Cheker e Messenger
controller_str = 'node controller(' + ", ".join('%s'%s for s in inputs_var) + ':int) returns(' + ", ".join('%s'%s for s in outputs_var) + ', msg: bool;' +' mode: modes)\n' \
'\tcontract\n' \
'\t\tvar\n'\
'\t\t\trule: bool;\n'\
'\t\tlet\n'\
'\t\t\tswitch mode\n'\
'\t\t\t\t' + '\n\t\t\t\t| Initial do rule = ' + ' & '.join('not %s'%s for s in outputs_var) + '\n'\
'\t\t\t\t| ' + '\n\t\t\t\t| '.join('%r do rule = %r' %(r[0], r[1]) for r in events).replace('\'', '') + ';' + '\n'\
'\t\t\tend\n'\
'\t\ttel\n'\
'\t\t\tenforce rule\n'\
'\t\t\twith (' + ', '.join('%s_c'%s for s in outputs_var) + ': bool)\n'\
'\t\tlet\n'\
'\t\t\t' + '\n\t\t\t'.join('%s = inlined device(%s_c);'%(s, s) for s in outputs_var) + '\n'\
'\t\t\tmode = inlined threshold_checker(' + ", ".join('%s'%s for s in inputs_var) + ');\n'\
'\t\t\tmsg = messenger(mode);\n'\
'\t\ttel'

# Escrevendo o código *.ept para a síntese do controlador.
file = open('irrigation.ept', 'w')
file.write(modes_str)
file.write(threshold_checker_str)
file.write(device_str)
file.write(messenger_str)
file.write(controller_str)

file.close()