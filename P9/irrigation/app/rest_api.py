#!/usr/bin/python3
# -*- coding: utf-8 -*-
# encoding=utf8

import os
import urllib3
import json
import requests
from requests.exceptions import ConnectionError

SERVER_HOST = '127.0.0.1:8082'

def get_status_devices(temperature_var=0):

	result = []
	url = 'http://' + SERVER_HOST + '/?temperature_var=' + str(temperature_var)

	try:

		result = requests.get(url)
		# print result
		json_message = json.loads(result.content.replace("'", "\"").replace("{,", "{"))
		# print result
		return json_message
	except ConnectionError:
		print "Não foi possível se conectar com o servidor."

print get_status_devices(55)
