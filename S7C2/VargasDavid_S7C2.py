# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2))/((x-x_0)**2 + a**2)

x = np.linspace(-4,4,1000)
plt.figure()
plt.plot(x, mifun(x))
plt.savefig("funcion")

# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 


def MCMC(N,sigma):
    lista = []
    guess= 8*np.random.random()-4   
    lista.append(guess)
    for i in range (N):
        nuevo = np.random.normal(lista[i],sigma)
        alpha = mifun(nuevo)/mifun(guess)      
        if alpha > 1:
            lista.append(nuevo)
        else:
            beta = np.random.random()
            if beta < alpha:
                lista.append(nuevo)
            else:
                lista.append(lista[i])
    return lista

normal = np.sum(mifun(x)*(x[1]-x[0]))

plt.figure()
plt.title("sigma = 5, pasos =100000 ")
plt.plot(x, mifun(x)/normal, color = "blue")
plt.hist(MCMC(100000,5), bins = 40, density = True, color = "m")
plt.savefig("intento1")

plt.figure()
plt.title("sigma = 0.2, pasos =100000 ")
plt.plot(x, mifun(x)/normal, color = "blue")
plt.hist(MCMC(100000,0.2), bins = 40, density = True, color = "m")
plt.savefig("intento2")

plt.figure()
plt.title("sigma = 0.01, pasos =100000 ")
plt.plot(x, mifun(x)/normal, color = "blue")
plt.hist(MCMC(100000,0.01), bins = 40, density = True, color="m")
plt.savefig("intento3")

plt.figure()
plt.title("sigma = 0.1, pasos =1000 ")
plt.plot(x, mifun(x)/normal, color = "blue")
plt.hist(MCMC(1000,0.1), bins = 40, density = True, color ="m")
plt.savefig("intento4")

plt.figure()
plt.title("sigma = 0.1, pasos =100000 ")
plt.plot(x, mifun(x)/normal, color = "blue")
plt.hist(MCMC(100000,0.1), bins = 40, density = True, color="m")
plt.savefig("intento5")

plt.figure()
plt.title("sigma = 0.1, pasos =500000 ")
plt.plot(x, mifun(x)/normal, color = "blue")
plt.hist(MCMC(500000,0.1), bins = 40, density = True, color ="m")
plt.savefig("intento6")
                
        
        

# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000 
# sigma = 0.2, pasos =100000 
# sigma = 0.01, pasos =100000 
# sigma = 0.1, pasos =1000 
# sigma = 0.1, pasos =100000 
# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
