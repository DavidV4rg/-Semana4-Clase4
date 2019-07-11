import numpy as np
import matplotlib.pylab as plt

placa = np.loadtxt("data.txt")

plt.figure()
plt.imshow(placa)
plt.savefig("placa")

#placa1 = np.loadtxt("t0.txt")
#placa2 = np.loadtxt("t1.txt")
#placa3 = np.loadtxt("t2.txt")

#plt.figure()
#plt.imshow(placa1)
#plt.savefig("placa1")

#plt.figure()
#plt.imshow(placa2)
#plt.savefig("placa2")

#plt.figure()
#plt.imshow(placa3)
#plt.savefig("placa3")