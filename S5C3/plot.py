import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("data.dat", delimiter = ";")

t = datos[:,0]
x = datos[:,1]
v = datos[:,2]

plt.figure(figsize= (20,10))
plt.plot(t,x, c="crimson", label = "$Posición$", linewidth = 3)
plt.plot(t,v, c="darkolivegreen", label= "$Velocidad$", linewidth = 2.5)
plt.legend()
plt.xlabel("Tiempo")
plt.savefig("plot")

