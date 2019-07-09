import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("datos.dat", delimiter = ";")

t=datos[:,0]
x=datos[:,1]

datos1 = np.genfromtxt("datos1.dat", delimiter = ";")

t1= datos1[:,0]
x1= datos1[:,1]

plt.figure(figsize=(15,8))
plt.subplot(1,2,1)
plt.plot(t,x)

plt.subplot(1,2,2)
plt.plot(t1, x1)
plt.savefig("VargasDavidplot1.pdf")