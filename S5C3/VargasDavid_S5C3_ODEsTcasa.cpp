#include <iostream>
#include <math.h> 
#include <fstream>

using namespace std;

double dxdt(float t, float x, float v);
double dvdt(float t, float x, float v);


double dvdt(float t, float x, float v)
{
    int k, masa;
    k = 2;
    masa = 200;
    return -k*x/masa;
}

double dxdt(float t, float x, float v)
{
    return v;
}
int main()
{
    int puntos = 1000;
    float t[puntos];
    float x[puntos];
    float v[puntos];
    float dt = 0.1;
    
    t[0] = 0.0;
    x[0] = 0.1;
    v[0] = 0.0;
    
    float mean1, mean2;
    float kx1, kx2, kx3, kx4;
    float kv1, kv2, kv3, kv4;
    
    for (int i = 1; i<=puntos; i++)
    {
        kx1 = dt*dxdt(t[i-1], x[i-1], v[i-1]);
        kv1 = dt*dvdt(t[i-1], x[i-1], v[i-1]);
        
        kx2 = dt*dxdt(t[i-1]+dt*0.5, x[i-1] + 0.5*kx1, v[i-1] + 0.5*kv1);
        kv2 = dt*dvdt(t[i-1]+dt*0.5, x[i-1] + 0.5*kx1, v[i-1] + 0.5*kv1);
        
        kx3 = dt*dxdt(t[i-1]+dt*0.5, x[i-1] + 0.5*kx2, v[i-1] + 0.5*kv2);
        kv3 = dt*dvdt(t[i-1]+dt*0.5, x[i-1] + 0.5*kx2, v[i-1] + 0.5*kv2);
        
        kx4 = dt*dxdt(t[i-1]+dt, x[i-1]+kx3, v[i-1]+kv3);
        kv4 = dt*dvdt(t[i-1]+dt, x[i-1]+kx3, v[i-1]+kv3);
        
        mean1 = (1.0/6.0)*(kx1 + 2*kx2+ 2*kx3 + kx4);
        mean2 = (1.0/6.0)*(kv1 + 2*kv2+ 2*kv3 + kv4);
        
        t[i]= t[i-1]+dt;
        x[i]= x[i-1]+mean1;
        v[i]= v[i-1]+mean2;

        
        cout << t[i-1] << ";" << x[i-1] << ";" << v[i-1] << endl;       
    }    
    return 0;
    
}
