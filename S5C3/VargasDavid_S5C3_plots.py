import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("data.dat", delimiter = ";")

t = datos[:,0]
x = datos[:,1]
v = datos[:,2]

plt.figure(figsize= (10,13))


plt.subplot(3,1,1)
plt.plot(t,x, c="crimson", linewidth = 1.5)
plt.ylabel("$Posición$ $(m)$")
plt.xlabel("$Tiempo$ $(s)$")

plt.subplot(3,1,2)
plt.plot(t,v, c="darkolivegreen", linewidth = 1.5)
plt.ylabel("$Velocidad$ $(m/s)$")
plt.xlabel("$Tiempo$ $(s)$")

plt.subplot(3,1,3)
plt.plot(t,x, c="crimson", linewidth = 1.5, label = "$Posición$")
plt.plot(t,v, c="darkolivegreen", linewidth = 1.5, ls = "--", label="$Velocidad$")
plt.xlabel("$Tiempo$ $(s)$")
plt.legend()


plt.savefig("VargasDavidResorte.pdf")



