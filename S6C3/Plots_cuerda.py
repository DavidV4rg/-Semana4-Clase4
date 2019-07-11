import numpy as np
import matplotlib.pylab as plt

dato = np.genfromtxt("inicial.dat", delimiter = ";")
datos = np.genfromtxt("data.dat", delimiter= ";")

tiempo = dato[:,0]
pos = dato[:,1]
pos1= dato[:,2]

ti = datos[:,1]
x = datos[:,0]

plt.figure(figsize=(30,14))

plt.subplot(1,3,1)
plt.plot(tiempo, pos, label="inicial", c="r")
plt.grid()
plt.xlabel("$Longitud$ $(m)$")
plt.ylabel("$Amplitud$ $(m)$")
plt.legend()

plt.subplot(1,3,2)
plt.plot(tiempo, pos1, label ="primer paso", c = "g")
plt.grid()
plt.xlabel("$Longitud$ $(m)$")
plt.ylabel("$Amplitud$ $(m)$")
plt.legend()

plt.subplot(1,3,3)
plt.plot(ti, x, label= "siguientes pasos", c = "y")
plt.grid()
plt.xlabel("$Longitud$ $(m)$")
plt.ylabel("$Amplitud$ $(m)$")
plt.legend()


plt.savefig("cuerda.pdf")