import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("data.dat", delimiter = ";")

tiempo = datos[:,0]
pos = datos[:,1]
pos1 = datos[:,1]

plt.figure(figsize=(15,10))
plt.grid()
plt.xlabel("$Longitud$ $(m)$")
plt.ylabel("$Amplitud$ $(m)$")
plt.plot(tiempo, pos, label="inicial", c="r")
plt.plot(tiempo, pos1, label ="primer paso", c = "g")
plt.legend()
plt.savefig("cuerda")