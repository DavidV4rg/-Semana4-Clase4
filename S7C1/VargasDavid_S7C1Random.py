import numpy as np
import matplotlib.pylab as plt


#Ejercicio 0
#Lean el capitulo 5 del Landau (ver el programa del curso).

#Ejercicio 1
# Usando los generadores de numeros aleatorios de numpy (https://docs.scipy.org/doc/numpy-1.15.1/reference/routines.random.html):
# a) Genere 1000 numeros aleatorios que sigan una distribucion uniforme y esten entre -10 y 10. Haga un histograma y guardelo sin mostrarlo en un archivo llamado uniforme.pdf

a=np.random.uniform(-10,10,1000)
plt.figure()
plt.hist(a, bins=40)
plt.savefig("uniforme.pdf")


# a) Genere 1000 numeros aleatorios que sigan una distribucion gausiana centrada en 17 y de sigma 5. Haga un histograma y guardelo sin mostrarlo en un archivo llamado gausiana.pdf

b = np.random.normal(17, 5, 1000)
plt.figure()
plt.hist(b, bins=40)
plt.savefig("gaussiana.pdf")

# Ejercicio 2
# Escriba un programa en Python que: 
# Genere puntos aleatorios distribuidos uniformemente dentro de un cuadrado de lado 30.5. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado cuadrado.pdf. 

x = np.random.uniform(0,30.5,1000)
y = np.random.uniform(0,30.5,1000)

plt.figure()
plt.scatter(x, y, alpha=0.2)
plt.savefig("cuadrado.pdf")


# Genere puntos aleatorios distribuidos uniformemente dentro de circulo de radio 23. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado circulo.pdf. 

a_c = np.random.uniform(0,1,10000)*2*np.pi
r = 23*np.random.uniform(0,1,10000)

x1 = r*np.cos(a_c)
y1 = r*np.sin(a_c)

plt.figure()
plt.scatter(x1,y1,alpha=0.2)
plt.savefig("circulo.pdf")

# Ejercicio 3 
# Lean sobre caminatas aleatorias.
# Ejercicio 4
# Tome los puntos distribuidos aleatoriamente dentro del cuadrado y haga que cada punto siga una caminata aleatoria de 100 pasos. 
# La magnitud de los pasos de esta caminata debe seguir una distribucion gaussiana centrada en el punto y de sigma igual a 0.25
# Implemente condiciones de frontera periodicas: si un punto se "sale" de cuadrado por un lado, "entra" por el otro  

a=np.copy(x)
b=np.copy(y)
paso1=[]
paso2=[]
caminatax = []
caminatay = []

for i in range(100):
    for n in range(len(x)):
        x[n] = np.random.normal(x[n], 0.25)
        y[n] = np.random.normal(y[n], 0.25)
        caminatax.append(x[20])
        caminatay.append(y[20])
        if x[n] > 30.5:
            x[n] = x[n] - 30.5
        elif x[n] < 0:
            x[n]  = x[n] + 30.5
        if y[n] > 30.5:
            y[n] = y[n] - 30.5
        elif y[n] < 0:
            y[n] = y[n] + 30.5
            
# Grafique la distribucion final de puntos y guarde dicha grafica sin mostrarla en un archivo llamado DistCaminata.pdf
plt.figure()
plt.scatter(x,y, label= "$distribución$ $final$", alpha = 0.8, color="g")
plt.scatter(a,b, label = "$distribución$ $inicial$", alpha = 0.4, color = "y")
plt.legend()
plt.savefig("DistCaminata.pdf")
# Grafique la caminata de UNO de sus puntos y guarde dicha grafica sin mostrarla en un archivo llamado puntoCaminata.pdf
plt.figure()
plt.plot(caminatax, caminatay)
plt.title("$Caminata$ $para$ $el$ $punto$ $20$")
plt.savefig("puntoCaminata.pdf")

# Repita el proceso para sigma = 0.00025 y sigma= 2.5. Grafique la caminata de UNO de sus puntos para los distintos sigmas y guardela sin mostrarla en sigmaCaminata.pdf

camix = []
camiy = []
cx = []
cy = []

for i in range(100):  
    for n in range(0,len(x)):
        x[n] = np.random.normal(x[n], 0.0025)
        y[n] = np.random.normal(y[n], 0.0025)
        a[n]  = np.random.normal(x[n], 2.5)
        b[n]  = np.random.normal(x[n], 2.5)
        camix.append(x[20])
        camiy.append(y[20])
        cx.append(a[20])
        cy.append(b[20])
    
        if x[n] > 30.5:
            x[n] = x[n] - 30.5
        elif x[i] < 0:
            x[n]  = x[n] + 30.5
        if y[n] > 30.5:
            y[n] = y[n] - 30.5
        elif y[n] < 0:
            y[n] = y[n] + 30.5
        if a[n] > 30.5:
            a[n] = a[n] - 30.5
        elif a[i] < 0:
            a[n]  = a[n] + 30.5
        if b[n] > 30.5:
            b[n] = b[n] - 30.5
        elif b[n] < 0:
            b[n] = b[n] + 30.5
            
plt.figure(figsize=(10,7))
plt.subplot(1,2,1)
plt.title("$Caminata$ $para$ $el$ $punto$ $20$")
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.plot(camix, camiy, label= "$alpha=0.0025$", c= "m")
plt.legend()
plt.subplot(1,2,2)
plt.title("$Caminata$ $para$ $el$ $punto$ $20$")
plt.plot(cx,cy, label = "$alpha=2.5$", color = "k")
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.legend()
plt.savefig("sigmaCaminata.pdf")


# Repita el proceso para condiciones abiertas: si un punto se "sale" del cuadrado deja de ser considerado en la simulacion.
# Si le queda tiempo puede:

## Ejercicio  ####


#difusion: una gota de crema en un Cafe.
#Condiciones iniciales:
#Cafe: 10000 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 230
#Crema: 100 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 2

#Nota: si su codigo se esta demorando mucho en correr, puede usar 1000 particulas de cafe en vez de 10000.

cafe = np.random.uniform(0,1,10000)*2*np.pi
radio = (230**0.5)*np.random.uniform(0,1,10000)

x_1 = radio*np.cos(cafe)
y_1 = radio*np.sin(cafe)

crema=np.random.uniform(0,1,100)*2*np.pi
radio1 = (2**0.5)*np.random.uniform(0,1,100)

x_2 = radio1*np.cos(crema)
y_2 = radio1*np.sin(crema)

# 1) Haga una grafica de las condiciones iniciales donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheIni.pdf

plt.figure()
plt.title("$Café$ $con$ $crema$")
plt.scatter(x_1,y_1, alpha=0.75, color="sienna", label="$café$")
plt.scatter(x_2,y_2, alpha=0.45, color="wheat", label="$crema$")
plt.legend()
plt.savefig("CafeLecheIni.pdf")

#2) Todas las particulas deben hacer una caminata aleatoria de 1000 pasos. Los pasos en las coordenadas x y deben seguir una distribucion gausiana de sigma 2.5. Si va a usar coordenadas polares elija un sigma apropiado.
#

x_11=np.copy(x_1)
y_11=np.copy(y_1)
x_21=np.copy(x_2)
y_21=np.copy(y_2)

radius = 230**0.5
for i in range(1000):
    for n in range(len(x_1)):
        for p in range(len(x_1)):
            x_11[n] = np.random.normal(x_11[n], 2.5)
            y_11[n] = np.random.normal(y_11[n], 2.5)

            if x_11[n] > radius:
                x_11[n] = np.random.normal(x_11[p], 2.5)
            if y_11[n] > radius:
                y_11[n] = np.random.normal(y_11[p], 2.5)

for i in range(1000):            
    for m in range(len(x_2)):
        for t in range(len(x_2)):
            x_21[m] = np.random.normal(x_21[m], 2.5)
            y_21[m] = np.random.normal(y_21[m], 2.5)

            if x_21[m] > radius:
                x_21[m] = np.random.normal(x_21[t], 2.5)
            if y_21[n] > radius:
                y_21[m] = np.random.normal(y_21[t], 2.5)
            
plt.figure()
plt.scatter(x_1,y_1, alpha=0.75, color="sienna", label="$café$")
plt.scatter(x_2,y_2, alpha=0.45, color="wheat", label="$crema$")
plt.scatter(x_11,y_11, alpha=0.7, color="peru", label="$café$ $caminata$")
plt.scatter(x_21,y_21, alpha=0.5, color="lightyellow", label="$crema$ $caminata$")
        
        
#3) Condiciones de frontera: implemente unas condiciones tales que si la particulas "sale" del circulo, usted vuelva a dar el paso. Si no puede implementar solo las condiciones antes descritas, debe al menos escribir comentarios explicando que hace cada linea de codigo de las condiciones propuestas (comentado abajo)
#
# 4) Haga una grafica de las posiciones finales de las particulas despues de la caminata donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheFin.pdf
#

#Una posible implementacion de condiciones de frontera. Trate de hacer la suya propia sin usar esta. 
#Si usa esta (obtiene menos puntos) debe comentar cada una de las lineas explicando en palabras que hace el codigo. Debe tambien naturalmente usar los nombres de variables que uso en el resto de su codigo propio.
#indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>230)
#indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>230)
#while(len(indexcafe[0])>1):
#	xcafenuevo[indexcafe]=xcafe[indexcafe] + np.random.normal(0,sigma)
#	ycafenuevo[indexcafe]=ycafe[indexcafe] + np.random.normal(0,sigma)
#	indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>=230)
#while(len(indexcrema[0])>1):
#	xcremanuevo[indexcrema]=xcrema[indexcrema] + np.random.normal(0,sigma)
#	ycremanuevo[indexcrema]=ycrema[indexcrema] + np.random.normal(0,sigma)
#	indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>=230) 



	
