import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("data.dat", delimiter = ";")

t = datos[:,0]
x = datos[:,1]

plt.figure(figsize= (10,5))
plt.plot(t,x, c="crimson", linewidth = 1.5)
plt.ylabel("$Posición$ $(m)$")
plt.xlabel("$Tiempo$ $(s)$" )
plt.savefig("VargasDavidResorte.pdf")

