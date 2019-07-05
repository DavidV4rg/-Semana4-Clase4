#include <iostream>
#include <math.h> 
#include <fstream>

using namespace std;

void rungekutta(float *t, float *x, float*v, float dt);
//Función que halla la derivada de la velocidad

float dvdt(float t, float x, float v)
{
    float k = 2.0;
    float masa = 300;
    return -(k*x)/masa;   
}
//Función que halla la derivada de la posición
float dxdt(float t, float x, float v)
{
    return v;    
}

//Método que resuelve las dos ecuaciones diferenciales al tiempo con Runge Kutta de 4orden
void rungekutta(float *t, float *x, float*v, float dt)
{
    float t_in, x_in, v_in;
    float kx1, kx2, kx3, kx4;
    float kv1, kv2, kv3, kv4;
    
    t_in = *t;
    x_in = *x;
    v_in = *v;
    
    kx1 = dxdt(t_in, x_in, v_in);
    kv1 = dvdt(t_in, x_in, v_in);    
    kx2 = dxdt(t_in + dt/2, x_in + kx1 * dt/2, v_in + kv1 * dt/2);
    kv2 = dvdt(t_in + dt/2, x_in + kx1 * dt/2, v_in + kv1 * dt/2);
    kx3 = dxdt(t_in + dt/2, x_in + kx2 * dt/2, v_in + kv2 * dt/2);
    kv3 = dvdt(t_in + dt/2, x_in + kx2 * dt/2, v_in + kv2 * dt/2);
    kx4 = dxdt(t_in + dt, x_in + kx3 * dt, v_in+ kv3 *dt);
    kv4 = dvdt(t_in + dt, x_in + kx3 * dt, v_in+ kv3 *dt);
    
    t_in = t_in + dt;
    x_in = x_in + dt * (kx1 + 2*kx2 + 2*kx3 + kx4)*(1.0/6.0);
    v_in = v_in + dt + (kv1 + 2+kv2 + 2*kv3 + kv4)*(1.0/6.0);
    
    *t = t_in;
    *x = x_in;
    *v = v_in;
}


int main()
{
    int t = 0;
    int tf = 5;
    float x = 0.1;
    float v = 0;
    float dt = 0.01;
    float puntos = (tf-t)/dt;
    
    for (int i = 1; i<= puntos; i++)
    {
        cout << t << ";" << x << ";" << v <<endl;
        rungekutta(&t, &x, &v, dt);
    
    }
   
    return 0;    
    

}