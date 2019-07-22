#include <iostream>
#include <fstream>

using namespace std;

/*
Ejercicio 4
Resuelva el siguiente sistema acoplado de ecuaciones diferenciales 
dx/dt = sigma * (y - x)
dy/dt = rho * x - y -x*z
dz/dt = -beta * z + x * y
con sigma = 10, beta=2.67, rho=28.0,
condiciones iniciales t=0, x=0.5, y=-1.0, z=1.0, hasta t=5.0.
Prepare dos graficas con la solucion: de x vs y (xy.png), x vs. z (xz.png) 
*/

float dxdt(t_i, x_i, y_i, z_i);
float dydt(t_i, x_i, y_i, z_i);
float dzdt(t_i, x_i, y_i, z_i);

float dxdt(t_i, x_i, y_i, z_i)
{
    sigma = 10;
    return sigma*(y_i-x_i);
}

float dydt(t_i, x_i,y_i,z_i)
{
    rho = 28.0;
    return rho* x_i-y_i - x_i*z_i;
}

float dzdt(t_i, x_i,y_i,z_i)
{
    beta = 2.67;
    return -beta*z_i+x_i*y_i;
}

int main()
{
    puntos = 1000;
    dx = 0.01;
    float x[puntos], y[puntos], z[puntos], t[puntos];
    float k1x, k2x, k3x, k4x;
    float k1y, k2y, k3y, k4y;
    float k1z, k2z, k3z, k4z;
    float mean;
    float t[0] = 0;
    float t[puntos] = 5.0;
    float x[0] = 0.5;
    float y[0] = -1.0;
    float z[0] = 1.0;
    
    for (int i = 1; i <puntos; i++)
    {
        
    }
    
    
        
    
    return 0;
}


        