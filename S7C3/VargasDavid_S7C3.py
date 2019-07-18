#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib.pylab as plt


# 1) lea los datos de resorte.dat y almacenelos.
# 
datos = np.genfromtxt("resorte.dat")
tiempo = datos[:,0]
posi = datos[:,1]

plt.figure()
plt.scatter(tiempo,posi, alpha = 0.6, color ="m")
plt.savefig("inicial")

# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por  
# xt=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:

# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  

def modelo(tiempo, a, gamma, omega):
    return a*np.exp(-gamma*tiempo)*np.cos(omega*tiempo)

# 2b.) Definir una funcion que retorne la funcion de verosimilitud

def likelihood(posi, pos_mod):
    chi = np.sum((posi-pos_mod)**2)
    var = np.exp*(0.5*-chi)
    return var

# 2c.) Caminata

#condiciones iniciales
aini=7.5
gammaini=0.6
omegaini=18.2

#numero de pasos
iteraciones=100000

# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."

datos = np.genfromtxt("resorte.dat")
tiempo = datos[:,0]
posi = datos[:,1]


def modelo(tiempo, a, gamma, omega):
    return a*np.exp(-gamma*tiempo)*np.cos(omega*tiempo)


def likelihood(posi, pos_mod):
    chi = np.sum((posi-pos_mod)**2)
    var = np.exp(0.5*-chi)
    return var

aini=7.5
gammaini=0.6
omegaini=18.2
iteraciones=100000

a_ = []
gamma_ = []
omega_ = []
l_i = []

a_.append(np.random.random()) #walk
gamma_.append(np.random.random())
omega_.append(np.random.random())
l_i.append(np.random.random())


def baye(sigma, N):
    for i in range (N):        
        a_[0] = aini
        gamma_[0] = gammaini
        omega_[0] = omegaini
        pos_in = modelo(tiempo, a_[0], gamma_[0], omega_[0])
        l_i[0] = likelihood(posi, pos_in)
        
        caminata_a = np.random.normal(a_[i], sigma) #prime
        caminata_g = np.random.normal(gamma_[i], sigma)
        caminata_o = np.random.normal(omega_[i], sigma) 
        
        old = modelo(tiempo, a_[i], gamma_[i], omega_[i])
        novo = modelo(tiempo, caminata_a, caminata_g, caminata_o)
        l_p = likelihood(posi, old)
        
        like_old = likelihood(posi, old)
        like_novo = likelihood(posi, novo)
        
        alpha = like_novo/like_old
        
        if (alpha>=1):
            a_.append(caminata_a)
            gamma_.append(caminata_g)
            omega_.append(caminata_o)
            l_i.append(l_p)
        else:
            beta = np.random.random()
            if(beta <= alpha):
                a_.append(caminata_a)
                gamma_.append(caminata_g)
                omega_.append(caminata_o)
                l_i.append(l_p)
            else:
                a_.append(a_[i])
                gamma_.append(gamma_[i])
                omega_.append(omega_[i])
                l_i.append(l_i[0])
    return l_i, a_, gamma_, omega_
indice = np.argmax(baye(0.1, iteraciones)[0])
ases = baye(0.1, iteraciones)[1]
gammas = baye(0.1, iteraciones)[2]
omegas = baye(0.1, iteraciones)[3]
eles = baye(0.1, iteraciones)[0]

print("Los mejores parametros son a=", ases[indice], "gamma=", gammas[indice], "omega = ", omegas[indice])

mejores = modelo(tiempo, ases[indice], gammas[indice], omegas[indice])

plt.figure(figsize=(10,7))
plt.plot(tiempo, mejores, color = "m", label = "$Mejores$ $Parametros$")
plt.plot(tiempo,posi, color = "c", label = "$Datos$ $originales$")
plt.xlabel("$Tiempo$")
plt.ylabel("$Posición$")
plt.legend()
plt.savefig("resorte.pdf")

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).

print("Se podría si se usan los mejores parámetros, no solo omega sino tambien gamma y a y se reemplazan en la ecuación original y se trata de despejar el valor de k y m.")



