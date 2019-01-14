#!/usr/bin/python3
# -*- coding: utf-8 -*-
# encoding=utf8

import time
from functools import reduce

import pandas as pd

def interpolacao(x,x1,x2,y,y1):
    eq1 = (x-x1)/(x2-x1)
    eq2 = (y1-y)
    result = y + (eq1*eq2)
    return result

def interpolacaoDados(tempo, srOut, srIn, tOut, tIn, tempo2, srOut2, srIn2, tOut2, tIn2):
    intervaloTempo = []
    interpolacaoSrOut = []
    interpolacaoSrIn = []
    interpolacaotOut = []
    interpolacaotIn = []

    for i in range(tempo+1, tempo2, 1):
        intervaloTempo.append(i)

    ##srout
    for t in intervaloTempo:
        interpolacaoSrOut.append(interpolacao(t,tempo,tempo2, srOut, srOut2))

    ##srin
    for t in intervaloTempo:
        interpolacaoSrIn.append(interpolacao(t,tempo,tempo2, srIn, srIn2))

    ##tout
    for t in intervaloTempo:
        interpolacaotOut.append(interpolacao(t,tempo,tempo2, tOut, tOut2))

    ##tin
    for t in intervaloTempo:
        interpolacaotIn.append(interpolacao(t,tempo,tempo2, tIn, tIn2))

    df = pd.DataFrame()

    df.loc[:,"Tempo"] = pd.Series(intervaloTempo)
    df.loc[:,"srOut"] = pd.Series(interpolacaoSrOut)
    df.loc[:,"srIn"] = pd.Series(interpolacaoSrIn)
    df.loc[:,"tOut"] = pd.Series(interpolacaotOut)
    df.loc[:,"tIn"] = pd.Series(interpolacaotIn)

    return df

def openDados():
    arq = open("dadosSimulador.txt","r")
    dados = arq.read().split("\n")

    result = []

    for d in dados:
        result.append(d.split(', '))

    result.pop(0)

    for i in range(0,len(result), 1):
        for j in range (0, len(result[i]),1):
            if j == 0:
                aux = result[i][j].split(":")
                result[i][j] = (int(aux[0])*60+int(aux[1]))*60
            else:
                result[i][j]= float(result[i][j])

    return result

def getDadosInterpolados():

    x = openDados()
    df_list = []

    for i in range(0, len(x)-1,1):
        line = x[i]
        line2 = x[i+1]

        tempo = line[0]
        srout= line[1]
        srin = line[7]
        tout = line[2]
        tin = line[8]

        tempo2 = line2[0]
        srout2= line2[1]
        srin2 = line2[7]
        tout2 = line2[2]
        tin2 = line2[8]

        df_list.append(interpolacaoDados(int(tempo) , srout,srin,tout,tin,int(tempo2),srout2,srin2,tout2,tin2))

    return reduce(lambda x,y : pd.concat([x,y], ignore_index=True), df_list)
