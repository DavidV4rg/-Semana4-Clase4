#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int main()
{
    
    float dx = 0.05;
    float c = 300;
    float l = 1.0;
    float A0 = 0.1;
    int N_puntos = (l/dx)+1;
    float dt = (dx*0.5)/c;
    float xpast[N_puntos], xpres[N_puntos], xfutu[N_puntos], x[N_puntos];
    float t[N_puntos];        
    t[0] = 0;
    t[N_puntos] = l;
    x[0] = 0;
    xpast[0] = 0;
    xpres[0] = 0;
    xfutu[0] = 0;
    double r = pow((c*dt)/dx,2);    
    ofstream outfile;
    ofstream outfile1;
    outfile.open("data.dat");
    for (int i = 1; i<N_puntos+1; i++)
    {
        t[i] = t[i-1] + dx;
        
        if(t[i]<= l/2)
        {
            x[i] = (2*A0/l)*t[i];
            xpast[i] = x[i];
        }
        
        else
        {
            x[i] = -(2*A0/l)*t[i] + 2*A0;
            xpast[i] = x[i];
        }
    }
    
    for (int i = 0; i <=N_puntos; i++)
    {
        xfutu[i] = (r/2)*(xpast[i+1]+xpast[i-1]-2*xpast[i]) + xpast[i]; 
    }
    for (int i = 0; i<=N_puntos; i++)
    {
        outfile <<  t[i-1] << ";" << x[i-1] << ";" << xfutu[i-1] <<endl;
    }
    
   
    return 0;
}
