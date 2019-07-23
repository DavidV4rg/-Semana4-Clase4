import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def funcion(x,r):
    return r*np.cos(x) + r*np.sin(x)

datos = np.genfromtxt("canal_ionico.txt")
tiempo = datos[:,0]
posi = datos[:,1]

lista = []
def MCMC():
    numero = 15*np.random.random()*-5
    lista.append(numero)
    for i in range(len(tiempo)):
        nuevo = np.random.normal(lista[i], 0.1)
        alpha = funcion(nuevo)/funcion(numero)
        if(alpha >1):
            lista.append(nuevo)
        beta = np.random.random()
        if (beta < alpha):
            lista.append(nuevo)
        else:
            lista.append(lista[i])
    return lista


            
        
        
