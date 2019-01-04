#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psycopg2
import database_manager as manager

class RulesRepository(object):

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

	def insert_rule(self, expression):
		
		sql = "INSERT INTO Rules(expression) VALUES('" + expression + "');"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def get_rule(self, id):

		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT id, expression FROM Rules WHERE id = " + str(id) + ";"		
		try:
			cursor = __connection.cursor()
			cursor.execute(sql)
			__connection.commit()
			
			return cursor.fetchone()

		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			cursor.close()
			return None
		finally:
			cursor.close()

	def get_all_rules_as_dictionary(self):

		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT * FROM Rules;"
		try:
			cursor = __connection.cursor()
			cursor.execute(sql)
			__connection.commit()
			
			row = cursor.fetchone()

			rules = {}
			while row is not None:
				rules['R' + str(row[0])] = row[1]
				row = cursor.fetchone()

			cursor.close()
			
			return rules

		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			cursor.close()
			return None
		finally:
			cursor.close()

	def get_all_rules_as_list(self):

		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT * FROM Rules;"
		# "CREATE TABLE IF NOT EXISTS Rules(Id INTEGER PRIMARY KEY, Expression VARCHAR(500) NOT NULL);"
		try:
			cursor = __connection.cursor()
			cursor.execute(sql)
			__connection.commit()
			
			row = cursor.fetchone()

			rules = []
			while row is not None:
				rules.append(row)
				row = cursor.fetchone()

			cursor.close()
			
			return rules

		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			cursor.close()
			return None
		finally:
			cursor.close()

	def update_rule(self, id, expression):

		sql = "UPDATE Rules SET expression = '" + expression + "' WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def delete_rule(self, id):

		sql = "DELETE FROM Rules WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

# rules = RulesRepository("postgres", "osboxes.org", "localhost", "teste")

# # rules.insert_rule("t_var > 50 or t_var > 55")
# # rules.delete_rule(12)
# # rules.update_rule(13, "t_var < 30")
# # print rules.get_rule(3)
# print rules.get_all_rules_as_dictionary()
# # print rules.get_all_rules_as_list()

# for i in range(20):
# 	rules.delete_rule(i)

