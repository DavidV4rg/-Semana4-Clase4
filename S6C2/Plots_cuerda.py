import numpy as np
import matplotlib.pylab as plt


datos = np.genfromtxt("data.dat", delimiter = ";")
dato = np.genfromtxt("data1.dat", delimiter = ";")

t = datos[:,0]
x = datos[:,1]

t1 = dato[:,0]
x1 = dato[:,1]

plt.figure(figsize=(10,7))
plt.subplot(2,1,1)
plt.grid()
plt.xlabel("$Tiempo$ $(s)$")
plt.ylabel("$Posición$ $(m)$")
plt.plot(t,x, c= "g")

plt.subplot(2,1,2)
plt.grid()
plt.xlabel("$Tiempo$ $(s)$")
plt.ylabel("$Posición$ $(m)$")
plt.plot(t1,x1, c="r")
plt.savefig("cuerda.pdf")

