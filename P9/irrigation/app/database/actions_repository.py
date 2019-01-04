#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psycopg2
import database_manager as manager

class ActionsRepository(object):

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

	def insert_action(self, expression):
		
		sql = "INSERT INTO Actions(expression) VALUES('" + expression + "');"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def get_action(self, id):
		
		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT id, expression FROM Actions WHERE id = " + str(id) + ";"		
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

	def get_all_actions_as_dictionary(self):

		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT * FROM Actions;"
		try:
			cursor = __connection.cursor()
			cursor.execute(sql)
			__connection.commit()
			
			row = cursor.fetchone()

			actions = {}
			while row is not None:
				actions['A' + str(row[0])] = row[1]
				row = cursor.fetchone()

			cursor.close()
			
			return actions

		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			cursor.close()
			return None
		finally:
			cursor.close()

	def get_all_actions_as_list(self):

		__connection = psycopg2.connect(
			user = self.user,
			password = self.password,
			host = self.host,
			database = self.database,
		)

		sql = "SELECT * FROM Actions;"
		# "CREATE TABLE IF NOT EXISTS actions(Id INTEGER PRIMARY KEY, Expression VARCHAR(500) NOT NULL);"
		try:
			cursor = __connection.cursor()
			cursor.execute(sql)
			__connection.commit()
			
			row = cursor.fetchone()

			actions = []
			while row is not None:
				actions.append(row)
				row = cursor.fetchone()

			cursor.close()
			
			return actions

		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			cursor.close()
			return None
		finally:
			cursor.close()

	def update_action(self, id, expression):

		sql = "UPDATE Actions SET expression = '" + expression + "' WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

	def delete_action(self, id):

		sql = "DELETE FROM Actions WHERE id = " + str(id) + ";"
		self.__conn.start_connection()
		self.__conn.manage_table(sql)
		self.__conn.close_connection()

# actions = ActionsRepository("postgres", "osboxes.org", "localhost", "teste")

# actions.insert_action("bomb_device & not valve_device")
# actions.delete_action(12)
# actions.update_action(1, "bomb_device & valve_device")
# print actions.get_action(2)
# print actions.get_all_actions_as_dictionary()
# print actions.get_all_actions_as_list()

# for i in range(20):
# 	actions.delete_action(i)

