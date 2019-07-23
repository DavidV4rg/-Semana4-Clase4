import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def funcion(x, y):
    return 2*np.pi*(x**2+y**2)

datos = np.genfromtxt("canal_ionico.txt")
tiempo = datos[:,0]
posi = datos[:,1]

lista = []
lista1 = []
def MCMC():
    numero1 = 20*np.random.random()*-5
    numero2 = 24*np.random.random()*-7
    lista.append(numero1)
    lista1.append(numero2)
    for i in range(len(tiempo)):
        nuevo1 = np.random.normal(lista[i], 0.1)
        nuevo2 = np.random.normal(lista1[i], 0.1)
        alpha1 = funcion(nuevo1,nuevo1)/funcion(numero1,numero1)
        alpha2 = funcion(nuevo2,nuevo2)/funcion(numero2,numero2)
        if(alpha1 >1):
            lista.append(nuevo1)
        if(alpha2 >1):
            lista1.append(nuevo2)
        beta = np.random.random()
        if (beta < alpha1):
            lista.append(nuevo1)
        else:
            lista.append(lista[i])
        if(beta < alpha2):
            lista.append(nuevo2)
        else:
            lista.append(lista1[i])
    return lista, lista1


            
        
        
