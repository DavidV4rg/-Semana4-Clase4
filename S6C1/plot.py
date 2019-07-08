import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("datos.dat", delimiter = ";")

t=datos[:,0]
x=datos[:,1]

plt.figure()
plt.plot(t,x)
plt.savefig("plot")

datos1 = np.genfromtxt("datos1.dat", delimiter = ";")

t1= datos1[:,0]
x1= datos1[:,1]

plt.figure()
plt.plot(t1, x1)
plt.savefig("plot1")