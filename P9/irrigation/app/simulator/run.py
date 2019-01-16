#!/usr/bin/python3
# -*- coding: utf-8 -*-
# encoding=utf8

from utils import getDadosInterpolados
import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
import time
import csv
from teste3 import TemperatureModel
import requests
import os
import urllib3
import json
from requests.exceptions import ConnectionError

def writeCSVFile(filename, header, data):
    try:
        with open(filename + '.csv','wb') as csvfile:
            spamwriter = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
            spamwriter.writerow(header)
            for i in range(len(data)):
                spamwriter.writerow(data[i])
    finally:
        print('Successful')

def getAutomatStatus(tIn):

    SERVER_HOST = '127.0.0.1:8082'

    result = []
    url = 'http://' + SERVER_HOST + '/?temperature_var=' + str(tIn)

    try:
        result = requests.get(url)
        # print(result.content)
        json_message = json.loads(result.content.replace("'", "\"").replace("{,", "{"))
        # print(json_message)
        return json_message
    except ConnectionError:
        print "Não foi possível se conectar com o servidor."

def simuladorComControle(): # maxTemperatura, minTemperatura):
    #initial condicitions
    print("Interpolando")
    dados_interpolados = getDadosInterpolados()
    dados_interpolados.to_csv("dados_i2")
    size = len(dados_interpolados)
    tIn = 13.7
    n=size
    minutes = 1
    #time points
    t = np.linspace(0,size, n)
    t15 = np.linspace(0, int(size/(60*minutes)), int(size/(60*minutes)))
    #store soluciton
    x = np.empty_like(t)
    min15 = np.empty_like(t15)
    x[0] = tIn
    l_tOut = np.empty_like(t)
    l_tOut15 = []
    # l_tOut2 = []

    u = []
    print("Gerando Pontos")
    for i in range(0,size,1):
        configuracao = dados_interpolados.iloc[[i]]
        l_tOut[i] = configuracao["tOut"].values[0]

        t0= {
            "tOut" : configuracao["tOut"].values[0],
            "heidth" : 6.3,
            "etPlantas" : 7.4/(24*60*60),
            "etCooling" : 0, #Não esta usando (Calculado no a partir do GRout)
            "glassArea" : 674,
            "groundArea" : 300,
            "transmitance_g_m" : 0.9,
            "qGRout" : configuracao["srOut"].values[0],
            "number_heater" : 0,
            "heater_capacity" : 75000,
            "qv_ventilation_rate" : 0.0005, #0.003,
            "k" : 6.2
        }

        # print(t0["tOut"],"-",t0["qGRout"])

        u.append(t0)

    heater_status = 0
    ventilation_status = 0.0005
    system_test = []
    header = ['temperature', 'heater_status', 'fan_status']
    heater_s = []
    fan_s = []

    for i in range(1,n,1):
        tspan= [t[i-1],t[i]]
        if tIn:
            if i%(60*minutes) == 0:
                print(tIn,u[i]['tOut'])
                print('data: ', i, 'temperature: ', tIn)
                autConfig = getAutomatStatus(tIn)
            
                time.sleep(10)

                if autConfig['heater_device'] == 1:
                    heater_status = 2
                else:
                    heater_status = 0

                if autConfig['fan_device'] == 1:
                    ventilation_status = 0.003
                else:
                    ventilation_status = 0.0005

                if i%(60*minutes) == 0:
                	heater_s.append(autConfig['heater_device'])
                	fan_s.append(autConfig['fan_device'])

        u[i]["number_heater"] = heater_status
        u[i]["qv_ventilation_rate"] = ventilation_status
        z = odeint(TemperatureModel, tIn, tspan, args=(u[i],))
        # ttt.append(tIn)
        x[i]=z[1][0]
        tIn= z[1][0]

        if i%(60*minutes) == 0:
        	# l_tOut2.append(tIn)
        	l_tOut15.append(z[1][0])

    plt.axhline(y=20., color='#696969', linestyle='--')
    plt.axhline(y=25., color='#696969', linestyle='--')

    # for i in range(1, len(t15[:1000])):
    # 	if heater_s[i] != heater_s[i-1]:
    # 		plt.axvline(x=t15[i], color='#696969', linestyle='--')

    # t152, l_tOut152 = simuladorSemControle()

    #controlled greenhouse
	#uncontrolled greenhouse
    # plt.plot(t152,l_tOut152)
    plt.plot(t15, l_tOut15)
    # plt.step(t15[:1000], heater_s[:1000], where='post', color='red')
    # plt.step(t15[:100], fan_s[:100], where='post', color='black')
    # plt.plot(t15,heater_s)
    plt.xlabel('time')
    plt.ylabel('tIn(t)')
    plt.savefig('plot-control-simulator.png')
    plt.show()

    writeCSVFile('results_test', header, system_test)

def simuladorSemControle(): # maxTemperatura, minTemperatura):
    #initial condicitions
    print("Interpolando")
    dados_interpolados = getDadosInterpolados()
    dados_interpolados.to_csv("dados_i2")
    size = len(dados_interpolados)
    tIn = 13.7
    n=size
    minutes = 10
    #time points
    t = np.linspace(0,size, n)
    t15 = np.linspace(0, int(size/(60*minutes)), int(size/(60*minutes)))
    #store soluciton
    x = np.empty_like(t)
    min15 = np.empty_like(t15)
    x[0] = tIn
    l_tOut = np.empty_like(t)
    l_tOut15 = []
    l_tOut2 = []

    u = []
    print("Gerando Pontos")
    for i in range(0,size,1):
        configuracao = dados_interpolados.iloc[[i]]
        l_tOut[i] = configuracao["tOut"].values[0]

        t0= {
            "tOut" : configuracao["tOut"].values[0],
            "heidth" : 6.3,
            "etPlantas" : 7.4/(24*60*60),
            "etCooling" : 0, #Não esta usando (Calculado no a partir do GRout)
            "glassArea" : 674,
            "groundArea" : 300,
            "transmitance_g_m" : 0.9,
            "qGRout" : configuracao["srOut"].values[0],
            "number_heater" : 0,
            "heater_capacity" : 75000,
            "qv_ventilation_rate" : 0.0005, #0.003,
            "k" : 6.2
        }

        # print(t0["tOut"],"-",t0["qGRout"])

        u.append(t0)

    heater_status = 0
    ventilation_status = 0.0005
    system_test = []
    header = ['temperature', 'heater_status', 'fan_status']
    heater_s = []
    ttt = [13.7]

    for i in range(1,n,1):
        tspan= [t[i-1],t[i]]
        if tIn:
            if i%(60*minutes) == 0:
                print(tIn,u[i]['tOut'])
                print('data: ', i, 'temperature: ', tIn)
                autConfig = getAutomatStatus(tIn)
            
                time.sleep(0.001)
                heater_status = 0
                ventilation_status = 0.0005

                # system_test.append([tIn, autConfig['heater_device'], autConfig['fan_device']])
                # heater_s.append(autConfig['heater_device'])

        u[i]["number_heater"] = heater_status
        u[i]["qv_ventilation_rate"] = ventilation_status
        z = odeint(TemperatureModel, tIn, tspan, args=(u[i],))
        # ttt.append(tIn)
        x[i]=z[1][0]
        tIn= z[1][0]

        if i%(60*minutes) == 0:
        	l_tOut2.append(tIn)
        	l_tOut15.append(z[1][0])

    return t15, l_tOut15

simuladorComControle()

# line_up, = plt.plot([1,2,3], label='uncontrolled')
# line_down, = plt.plot([3,2,1], label='controlled')
# plt.legend(handles=[line_up, line_down])
# plt.show()

# plt.plot(t152,l_tOut152, label="uncontrolled")
# plt.plot(t15,l_tOut15, label="controlled")