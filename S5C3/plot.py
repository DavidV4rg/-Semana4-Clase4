import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("datos.dat", delimiter = ";")

t = datos[:,0]
x = datos[:,1]
v = datos[:,2]

plt.figure()
plt.plot(t,v, c="g", marker = "+")
plt.savefig("plot")

