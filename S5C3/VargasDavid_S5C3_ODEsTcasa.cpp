#include <iostream>
#include <math.h> 
#include <fstream>

using namespace std;
//Se declaran primero los metodos que usaré para hallar las derivadas
double dxdt(float t_in, float x_in, float v_in);
double dvdt(float t_in, float x_in, float v_in);

//Se crea el método que va a calcular la derivada de la velocidad con respecto al tiempo
double dvdt(float t_in, float x_in, float v_in)
{
    int k, masa;
    k = 300;
    masa = 2;
    return -(k*x_in)/masa;
}
//Se crea el método que va a calcular la derivada de la posición con respecto al tiempo
double dxdt(float t_in, float x_in, float v_in)
{
    return v_in;
}

//Dentro del main hago el metodo de runge kutta
int main()
{
    //tiempo inicial
    int t0 = 0;
    //tiempo final
    int tf = 5; 
    //delta de tiempo para hallar la derivada
    double dt = 0.001;
    //Número de puntos que se usarán para poder hallar las derivadas
    int puntos = (tf-t0)/dt;
    //Arreglos del tiempo, posición y velocidad
    float t[puntos];
    float x[puntos];
    float v[puntos];
    //se declaran las condiciones inicales para que Runge Kutta pueda funcionar
    t[0] = 0.0;
    x[0] = 0.1;
    v[0] = 0.0;
    //Variables que se usarán para hallar las derivadas en cada ciclo.
    float mean1, mean2;
    float kx1, kx2, kx3, kx4;
    float kv1, kv2, kv3, kv4;
    
    //Bucle que va a calcular las derivadas 
    for (int i = 1; i<=(puntos-1); i++)
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
