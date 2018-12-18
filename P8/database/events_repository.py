#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psycopg2
import database_manager as manager
import rules_repository
import actions_repository

class EventsRepository(object):

	def __init__(self, user, password, host, database):

		self.user = user
		self.password = password
		self.host = host
		self.database = database

		self.__conn = manager.Connection (
			user, 
			password, 
			host, 
			database,
		)

	def insert_event(self, rule_id, action_id):
		
		sql = "INSERT INTO Events(rule_id, action_id) VALUES('" + str(rule_id) + "', '" + str(action_id) + "');"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def get_event(self, id):

		sql = "SELECT id, expression FROM Events WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		rule = self.__conn.manage_table(sql)
		self.__conn.close_connection()
		return rule

	def get_all_events_as_list(self):

		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT * FROM Events;"
		# "CREATE TABLE IF NOT EXISTS Events(Id INTEGER PRIMARY KEY, Expression VARCHAR(500) NOT NULL);"
		try:
			cursor = __connection.cursor()
			cursor.execute(sql)
			__connection.commit()
			
			row = cursor.fetchone()

			Events = []
			while row is not None:
				Events.append(row)
				row = cursor.fetchone()

			cursor.close()
			
			return Events

		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			cursor.close()
			return None
		finally:
			cursor.close()

	def update_event(self, id, rule_id, action_id):

		sql = "UPDATE Events SET rule_id = '" + rule_id + "', action_id = '" + action_id + "' WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def delete_event(self, id):

		sql = "DELETE FROM Events WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def get_rules_actions_events(self):

		r = rules_repository.RulesRepository("postgres", "osboxes.org", "localhost", "teste")
		# r.insert_rule("t_var < 30")
		a = actions_repository.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
		# # a.insert_action("bomb_device & valve_device")
		e = EventsRepository("postgres", "osboxes.org", "localhost", "teste")

		events = e.get_all_events_as_list()

		ru = [r.get_rule(i[1])[1] for i in events]
		ac = [a.get_action(i[2])[1] for i in events]

		rules = {}
		for i in range(len(ru)):
			rules['R' + str(i)] = ru[i]

		actions = {}
		for i in range(len(ac)):
			actions['A' + str(i)] = ac[i]

		rule_name_expr = [[r_name, r_expr] for r_name, r_expr in rules.items()]
		action_name_expr = [[a_name, a_expr] for a_name, a_expr in actions.items()]

		ev = [[rule_name_expr[i][0], action_name_expr[i][1]] for i in range(len(rule_name_expr))]

		return ru, ac, ev, rule_name_expr, action_name_expr

# r = rules.RulesRepository("postgres", "osboxes.org", "localhost", "teste")
# # r.insert_rule("t_var < 30")
# a = actions.ActionsRepository("postgres", "osboxes.org", "localhost", "teste")
# # # a.insert_action("bomb_device & valve_device")

# print e.get_all_events_as_list()
# e.delete_event(2)
# print e.get_all_events_as_list()
# rule_id = r.get_rule(18)
# action_id = a.get_action(3)

# print rule_id
# print action_id

# if rule_id != None and action_id != None:
# 	e.insert_event(rule_id[0], action_id[0])
# else:
# 	print "Não foi possível inserir evento no banco"





# return rules, actions, events

