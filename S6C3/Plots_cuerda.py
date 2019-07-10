import numpy as np
import matplotlib.pylab as plt

dato = np.genfromtxt("inicial.dat", delimiter = ";")
datos = np.genfromtxt("data.dat", delimiter= ";")

tiempo = dato[:,0]
pos = dato[:,1]
pos1= dato[:,2]

ti = datos[:,1]
x = datos[:,0]

plt.figure(figsize=(15,10))
plt.grid()
plt.xlabel("$Longitud$ $(m)$")
plt.ylabel("$Amplitud$ $(m)$")
plt.plot(tiempo, pos, label="inicial", c="r")
plt.plot(tiempo, pos1, label ="primer paso", c = "g")
plt.plot(ti, x, label= "siguientes pasos", c = "y")
plt.legend()
plt.savefig("cuerda.pdf")