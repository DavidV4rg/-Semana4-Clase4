import numpy as np
import matplotlib.pylab as plt

# Ejercicio1
# A partir de los arrays x y fx calcule la segunda derivada de fx con respecto a x. 
# Esto lo debe hacer sin usar ciclos 'for' ni 'while', solamente puede usar 'slicing' (i.e. a[2:-2])
# Guarde esta segunda derivada en funcion de x en una grafica llamada 'segunda.png'

x = np.linspace(0,2.,10)
fx = np.array([0., 0.0494, 0.1975, 0.4444, 0.7901,1.2346 , 1.7778, 2.4198, 3.1605, 4.])

delta = (x[1]-x[0])/2
k = fx[1::]
j = fx[0:-1]
segunda = (k - 2*fx[1::] + j)/delta**2

plt.figure()
plt.plot(x[0:-1], segunda)
plt.savefig("segunda")


# Ejercicio 2
# Complete el siguiente codigo para recorrer la lista `x` e imprima
# los numeros impares mayores que 100 y que pare de imprimir al encontrar un numero primo.
x = np.int_(np.random.random(100)*10000)
lista = []
primos = []
for i in range(len(x)):
    if (x[i]%2 != 0 and x[i]>100):
        lista.append(x[i])
for i in range(len(lista)):
    for j in range(1, i):
        if (lista[i]%j == 0):
            primos.append(lista[i])          
            
            
#Ejercicio 3
# 'y' es una senal en funcion del tiempo 't' con las unidades descritas en el codigo.
# a. Grafique la senal en funcion del tiempo en la figura 'senal.png' ('y' vs. 't')
# b. Calule la transformada de Fourier (sin utilizar funciones de fast fourier transform) y
# grafique la norma de la transformada en funcion de la frecuencia (figura 'fourier.png')
# c. Lleve a cero los coeficientes de Fourier con frecuencias mayores que 10000 Hz y calcule 
# la transformada inversa para graficar la nueva senal (figura 'filtro.png')
n = 512 # number of point in the whole interval
f = 200.0 #  frequency in Hz
dt = 1 / (f * 128 ) #128 samples per frequency
t = np.linspace( 0, (n-1)*dt, n) 
y = np.sin(2 * np.pi * f * t) + np.cos(2 * np.pi * f * t * t)
noise = 1.4*(np.random.rand(n)+0.7)
y  =  y + noise

plt.figure()
plt.plot(t, y)

def TF(señal):
    lista = []
    N = len(señal)
    for i in range (N):
        v = 0;
        for k in range(N):
            v += señal[k]*np.exp(-2j*np.pi*k*i*(1/N))
        lista.append(v)
    return lista

transfo = TF(y)
N = len(y)
delta = t[1]-t[0]
N_delta = N*delta

x1 =  np.linspace(0, (N/2)-1, N/2)
x2 = np.linspace(-(N/2), -1, N/2)

frecuencias = np.concatenate((x1,x2), axis= None)

plt.figure()
plt.plot(frecuencias,transfo)

tra = np.copy(transfo)

for i in range(len(frecuencias)):
    if(frecuencias[i] > 10000):
        tra[i] = 0

def ITF(señal):
    lista = []
    N = len(señal)
    for i in range (N):
        v = 0;
        for k in range(N):
            v += señal[k]*np.exp(2j*np.pi*k*i*(1/N))
        lista.append(v)
    return lista

inversa = ITF(tra)

plt.figure()
plt.plot(t, inversa)

# Ejercicio 4
# Resuelva el siguiente sistema acoplado de ecuaciones diferenciales 
# dx/dt = sigma * (y - x)
# dy/dt = rho * x - y -x*z
# dz/dt = -beta * z + x * y
# con sigma = 10, beta=2.67, rho=28.0,
# condiciones iniciales t=0, x=0.5, y=-1.0, z=1.0, hasta t=5.0.
# Prepare dos graficas con la solucion: de x vs y (xy.png), x vs. z (xz.png) 
