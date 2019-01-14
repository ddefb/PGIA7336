#!/usr/bin/python3
# -*- coding: utf-8 -*-
# encoding=utf8

# USANDO ESSE AQUI Q ESTA CERTO

import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
from random import randint
from utils import getDadosInterpolados

# function that returns dy/dt and dx/dt
CP = 1010  #Calor especifico do ar (J kg^(-1) K^(-1))
L = 2.5 * 10**(6) # Calor latente da agua (J/kg)
#L = 2260 * 1000 # Calor latente da agua (J/kg)
STEFAN_BOLTZMAN = 5.67 * 10**(-8) #Constante de Sfetan-Boltzman (W m^−2 K^−4)
REFLECTANCIA_SOLO = 0.5 #sem dimensão
SPECIFC_MASS_AIR = 1.25
qv = 0 #m^3/m^2*s

def QGRinEq(transmitance_g_m, qgrout):
    return transmitance_g_m*(1-REFLECTANCIA_SOLO)*qgrout

def QheaterEq(number_heater, heater_capacity, ground_surface):
    #heater_capacity esta e, kW
    return number_heater*(heater_capacity/ground_surface)

def EtEq(qgrout, transmitance_g_m, cropType):
    if cropType == "small":
        return 0.00006 * transmitance_g_m * qgrout + 0.0004
    elif cropType == "large":
        return 0.0003 * transmitance_g_m * qgrout + 0.0021
    else:
        return 0

def EvapotranspirationEq(etCooling, etPlantas):
    return (etCooling+etPlantas)#/86400

def TemperatureModel(tIn, t, parameters):
    tOut = parameters["tOut"]
    heidth = parameters["heidth"]
    etPlantas = parameters["etPlantas"]
    etCooling = parameters["etCooling"]
    glassArea = parameters["glassArea"]
    groundArea = parameters["groundArea"]
    transmitance_g_m = parameters["transmitance_g_m"]
    qGRout = parameters["qGRout"]
    number_heater = parameters["number_heater"]
    heater_capacity = parameters["heater_capacity"]
    qv_ventilation_rate = parameters["qv_ventilation_rate"]
    k = parameters["k"]

    # print(tOut,"-",qGRout)

    #Radiacao solar dentro da gh
    qGRin = QGRinEq(transmitance_g_m, qGRout)

    #Quantidade de calor gerada pelo aquecedor
    qHearter = QheaterEq(number_heater, heater_capacity, groundArea)

    #Evapotranpiracao
    Et = EtEq(qGRout, transmitance_g_m, 'smalll')/(24*60*60)
    E = EvapotranspirationEq(Et, etPlantas)


    #Area de vidro/Area de chao
    w = glassArea/groundArea

    # q1 = qGRin + qHearter - L*E - (tIn - tOut)
    # q2 = qv_ventilation_rate * CP * SPECIFC_MASS_AIR + w * k
    # q3 = CP * SPECIFC_MASS_AIR * heidth
    # dTindt = q1*q2/q3

    q1 = qGRin + qHearter - L*E - (tIn - tOut) * (qv_ventilation_rate * CP * SPECIFC_MASS_AIR + w * k)
    # q3 = CP * SPECIFC_MASS_AIR * heidth
    q3 = 1010 * 1.2 * 10
    dTindt = q1/q3
    # dTindt = (qGRin + qHearter - L*E - (tIn - tOut)) * \
    #          (qv_ventilation_rate * CP * SPECIFC_MASS_AIR + w * k)/ \
    #          (CP * SPECIFC_MASS_AIR * heidth)

    return dTindt

parameters = {
    "tOut" : 24,
    "heidth" : 10,
    "etPlantas" : 8.9,
    "etCooling" : 14.8,
    "glassArea" : 674,
    "groundArea" : 300,
    "transmitance_g_m" : 0.9,
    "qGRout" : 0,
    "number_heater" : 0,
    "heater_capacity" : 75000,
    "qv_ventilation_rate" : 0.03,
    "k" : 6.2
}


#
# #initial condicitions
# dados_interpolados = getDadosInterpolados()
# dados_interpolados.to_csv("dados_i")
# size = len(dados_interpolados)
# tIn = 13.7
# n=size
# #time points
# t = np.linspace(0,size, n)
# #store soluciton
# x = np.empty_like(t)
# x[0] = tIn
# l_tOut = np.empty_like(t)
# #
# # # u = []
# # # for i in range(0,size,1):
# # #     t0= {
# # #         "tOut" : 13.28,
# # #         "heidth" : 6.3,
# # #         "etPlantas" : 7.4/(24*60*60),
# # #         "etCooling" : 0,
# # #         "glassArea" : 674,
# # #         "groundArea" : 300,
# # #         "transmitance_g_m" : 0.9,
# # #         "qGRout" : 800,
# # #         "number_heater" : randint(0,0),
# # #         "heater_capacity" : 75000,
# # #         "qv_ventilation_rate" : 0.0005, #0.003,
# # #         "k" : 6.2
# # #     }
# # #     u.append(t0)
# #
# # # teste interpolação
# u = []
# for i in range(0,size,1):
#     configuracao = dados_interpolados.iloc[[i]]
#     l_tOut[i] = configuracao["tOut"].values[0]
#     t0= {
#         "tOut" : configuracao["tOut"].values[0],
#         "heidth" : 6.3,
#         "etPlantas" : 7.4/(24*60*60),
#         "etCooling" : 0,
#         "glassArea" : 674,
#         "groundArea" : 300,
#         "transmitance_g_m" : 0.9,
#         "qGRout" : configuracao["srOut"].values[0],
#         "number_heater" : randint(0,0),
#         "heater_capacity" : 75000,
#         "qv_ventilation_rate" : 0.0005, #0.003,
#         "k" : 6.2
#     }
#
#     # print(t0["tOut"],"-",t0["qGRout"])
#
#     u.append(t0)
#
#
#
# # print(len(u))
# for i in range(1,n,1):
#     tspan= [t[i-1],t[i]]
#     z = odeint(TemperatureModel, tIn, tspan, args=(u[i],))
#     x[i]=z[1][0]
#     tIn= z[1][0]
# #
# plt.plot(t,x)
# plt.plot(t,l_tOut)
# plt.xlabel('time')
# plt.ylabel('tIn(t)')
# plt.show()