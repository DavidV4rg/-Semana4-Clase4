#include <iostream>
#include <math.h> 
#include <fstream>

using namespace std;

void rungekutta(float t_in, float x_in, floatv_in, float dt, float punt);
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
void rungekutta(float t_in, float x_in, floatv_in, float d, float punt)
{
    float kx1, kx2, kx3, kx4;
    float kv1, kv2, kv3, kv4;
    
    
    for (int i = 1; i<= punt; i++)
    {
        kx1 = d*dxdt(t[i-1], x[i-1], v[i-1]);
        kv1 = d*dvdt(t[i-1], x[i-1], v[i-1]);
        
        kx2 = d*dxdt(t[i-1] + 0.5*d, x[i-1]+0.5*kx1, v[i-1]+0.5*kv1);
        kv2 = d*dvdt(t[i-1] + 0.5*d, x[i-1]+0.5*kx1, v[i-1]+0.5*kv1);
        
        kx3 = d*dxdt(t[i-1] + 0.5*d, x[i-1]+0.5*kx2, v[i-1]+0.5*kv2);
        kv3 = d*dvdt(t[i-1] + 0.5*d, x[i-1]+0.5*kx2, v[i-1]+0.5*kv2);
        
        kx4 = d*dxdt(t[i-1]+ d, x[i-1] +kx3, v[i-1]+kv3);
        kv4 = d*dvdt(t[i-1]+ d, x[i-1] +kx3, v[i-1]+kv3);

    }
    
}


int main()
{
    int t = 0;
    int tf = 5;
    float dt = 0.01;
    float puntos = (tf-t)/dt;
    float x[puntos];
    float v[puntos];
    float t[puntos];
    
    for (int i = 1; i<= puntos; i++)
    {
        cout << t << ";" << x << ";" << v <<endl;
        rungekutta(&t, &x, &v, dt);
    
    }
   
    return 0;    
    

}