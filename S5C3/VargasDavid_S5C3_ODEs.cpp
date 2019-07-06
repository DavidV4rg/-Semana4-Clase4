#include <iostream>
#include <math.h> 
#include <fstream>

using namespace std;

//Se declara primero la función que va a resolver las ecuaciones diferenciales

//void rungekutta(float t, float x, float v, float d);

//Se declara la función que halla la derivada de la velociodad
float dvdt(float t, float x, float v);

//Se declara la función que halla la derivada de la posición
float dxdt(float t, float x, float v);

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
/*
void rungekutta(float t, float x, float v, float d)
{
    
    ofstream oufile;
    outfile.open("datos.dat");
   
    
    float kx1, kx2, kx3, kx4;
    float kv1, kv2, kv3, kv4;
    
    v[0] = 0;
    x[0] = 0.1;
    

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
        
        float mean1, mean2;
        mean1 = (1.0/6.0)* (kx1 + 2*kx2 + 2*kx3 + kx4);
        mean2 = (1.0/6.0)* (kv1 + 2*kv2 + 2*kv3 + kv4);
        x[i] = x[i-1] + mean1;
        v[i] = x[i-1] + mean2;
        t[i] = t[i-1] + d;
        
        cout << t << "" << x << "" << v << endl;
    }
    //outfile.close();
}

*/

int main()
{
    int t0 = 0;
    int tf = 5;
    float dt = 0.01;
    int puntos = (tf-t0)/dt;
    float x[puntos];
    float v[puntos];
    float t[puntos];
    
    float kx1, kx2, kx3, kx4;
    float kv1, kv2, kv3, kv4;
    
    v[0] = 0;
    x[0] = 0.1;
    t[0] = 0;
    

    for (int i = 1; i<= puntos; i++)
    {
        kx1 = dt*dxdt(t[i-1], x[i-1], v[i-1]);
        kv1 = dt*dvdt(t[i-1], x[i-1], v[i-1]);
        
        kx2 = dt*dxdt(t[i-1] + 0.5*dt, x[i-1]+0.5*kx1, v[i-1]+0.5*kv1);
        kv2 = dt*dvdt(t[i-1] + 0.5*dt, x[i-1]+0.5*kx1, v[i-1]+0.5*kv1);
        
        kx3 = dt*dxdt(t[i-1] + 0.5*dt, x[i-1]+0.5*kx2, v[i-1]+0.5*kv2);
        kv3 = dt*dvdt(t[i-1] + 0.5*dt, x[i-1]+0.5*kx2, v[i-1]+0.5*kv2);
        
        kx4 = dt*dxdt(t[i-1]+ dt, x[i-1] +kx3, v[i-1]+kv3);
        kv4 = dt*dvdt(t[i-1]+ dt, x[i-1] +kx3, v[i-1]+kv3);
        
        float mean1, mean2;
        mean1 = (1.0/6.0)* (kx1 + 2*kx2 + 2*kx3 + kx4);
        mean2 = (1.0/6.0)* (kv1 + 2*kv2 + 2*kv3 + kv4);
        x[i] = x[i-1] + mean1;
        v[i] = x[i-1] + mean2;
        t[i] = t[i-1] + dt;
        
        cout << t[i-1] << ";" << x[i-1] << ";" << v[i-1] << endl;
    }
  
    return 0;    
    

}