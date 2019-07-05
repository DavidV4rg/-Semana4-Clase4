import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("datos.dat", delimiter = "||")

x= datos[:,0]
y= datos[:,1]

x1 = x[0:199]
y1 = y[0:199]

x2 = x[199::]
y2 = y[199::]


plt.figure(figsize=(15,5))
plt.subplot(1,2,1)
plt.plot(x1, np.exp(-x1), color = "r", label = "$y(x)$ $=$ $exp(-x)$" )
plt.plot(x1, y1, color="b", label = "$Función$ $usando$ $el$ $método$ $de$ $Euler$", ls = "--")
plt.legend()
plt.xlabel("$x$")
plt.ylabel("$y$")

plt.subplot(1,2,2)
plt.plot(x1, np.exp(-x1), color = "r", label = "$y(x)$ $=$ $exp(-x)$" )
plt.plot(x2, y2, color="c", label = "$Función$ $usando$ $el$ $método$ $de$ $Runge$ $Kutta$", ls = "--" )
plt.legend()
plt.xlabel("$x$")
plt.ylabel("$y$")

plt.savefig("plotdatos.pdf")