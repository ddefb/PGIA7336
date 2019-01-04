#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psycopg2

class Connection(object):

	def __init__(self, user, password, host, database):
		self.__connection = None
		self.__username = user
		self.__password = password
		self.__host = host
		self.__database = database

	def create_database(self):
		try:
			self.__connection = psycopg2.connect(
				user = self.__username,
				password = self.__password,
				host = self.__host,
			)

			self.__connection.autocommit = True
			cursor = self.__connection.cursor()
			cursor.execute("CREATE DATABASE " + self.__database + ";")
		
		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)

	def drop_database(self):
		try:
			self.__connection = psycopg2.connect(
				user = self.__username,
				password = self.__password,
				host = self.__host,
			)

			self.__connection.autocommit = True
			cursor = self.__connection.cursor()
			cursor.execute("DROP DATABASE IF EXISTS " + self.__database + ";")
		
		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)

	def start_connection(self):
		try:
			self.__connection = psycopg2.connect(
				user = self.__username,
				password = self.__password,
				host = self.__host,
				database = self.__database
			)

			cursor = self.__connection.cursor()
			# Print PostgreSQL version
			cursor.execute("SELECT version();")
			record = cursor.fetchone()
			print("You are connected to - ", record,"\n")
		
		except (Exception, psycopg2.Error) as error :
			# print ("Error while connecting to PostgreSQL", error)
			if 'database' and 'does not exist' in str(error):
				self.create_database()
				self.start_connection()

	def close_connection(self):
		if(self.__connection):
			try:
				cursor = self.__connection.cursor()
				cursor.close()
				self.__connection.close()
				print("PostgreSQL connection is closed")
			except (Exception, psycopg2.Error) as error :
				print ("Error while connecting to PostgreSQL", error)

	def manage_table(self, sql):
		try:
			cursor = self.__connection.cursor()
			cursor.execute(sql)
			self.__connection.commit()
			cursor.close()
			
		except (Exception, psycopg2.Error) as error :
			print ("Error while connecting to PostgreSQL", error)
			
			return False

# if __name__ == '__main__':

# 	conn = Connection("postgres", "osboxes.org", "localhost", "teste")
# # 	# conn.create_database()
# # 	# conn.drop_database()
# 	conn.start_connection()

# # 	# conn.manage_table("DROP TABLE IF EXISTS Actions;")
# # 	# conn.manage_table("DROP TABLE IF EXISTS Rules;")
# 	# conn.manage_table("DROP TABLE IF EXISTS Events;")

# # 	# conn.start_connection()

# # 	# conn.manage_table("CREATE TABLE Rules(id SERIAL PRIMARY KEY, expression VARCHAR(500) NOT NULL);")
# # 	# conn.manage_table("CREATE TABLE Actions(id SERIAL PRIMARY KEY, expression VARCHAR(500) NOT NULL);")
# 	conn.manage_table("CREATE TABLE Events(id SERIAL PRIMARY KEY, rule_id INTEGER NOT NULL REFERENCES Rules(id), action_id INTEGER NOT NULL REFERENCES Actions(id));")

# 	conn.close_connection()
# 	