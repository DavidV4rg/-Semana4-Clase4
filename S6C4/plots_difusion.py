import numpy as np
import matplotlib.pylab as plt

placa = np.loadtxt("data.txt")
placa1 = np.loadtxt("Tiempo0.txt")
placa2 = np.loadtxt("Temp1.txt")

plt.figure(figsize=(15,10))


plt.subplot(1,3,1)
plt.imshow(placa)
plt.title("$Tiempo$ $0s$")

plt.subplot(1,3,2)
plt.imshow(placa1)
plt.title("$Tiempo$ $100s$")

plt.subplot(1,3,3)
plt.imshow(placa2)
plt.title("$Tiempo$ $2500s$")


plt.savefig("placa.pdf")