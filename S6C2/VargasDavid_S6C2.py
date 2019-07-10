import numpy as np
import matplotlib.pylab as plt


datos = np.genfromtxt("data.dat", delimiter = ";")

t = datos[:,0]
x = datos[:,1]

plt.figure()
plt.plot(t,x)
plt.savefig("inicial.pdf")

