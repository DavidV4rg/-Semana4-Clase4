import numpy as np
import matplotlib.pylab as plt
from matplotlib.colors import LogNorm

placa = np.loadtxt("data.txt")

plt.figure()
plt.imshow(placa)
plt.colorbar()
plt.savefig("placa")

placa1 = np.loadtxt("T0.txt")
placa2 = np.loadtxt("T1.txt")


plt.figure()
plt.imshow(placa1, norm = LogNorm())
plt.colorbar()
plt.savefig("placa1")


