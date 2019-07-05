#include <iostream>
#include <math.h> 
#include <fstream>

using namespace std;

float deriva(float x1, float y1)
{    
    return -y1;
}

int main()
{
    float dx=0.01;
    int a = 0;
    int b = 2
        ;
    int puntos = (b-a)/dx;
    float x[puntos];
    float y[puntos];
    
    for (int i = 1; i<= puntos-1; i++)
    {
        x[0]= a;
        y[0]= 1.0;
        x[i]= x[i-1]+dx;
        y[i]= y[i-1]+(dx*deriva(x[i-1], y[i-1]));
        cout<<x[i]<<"||"<<y[i]<<endl;
    }
    
    cout <<"\n"<<endl;
    
    for (int i = 1; i<= puntos-1; i++)
    {
        float k1 = dx*deriva(x[i-1],y[i-1]);
        float k2 = dx*deriva(x[i-1] +0.5*dx, y[i-1]+0.5 * k1);
        float k3 = dx*deriva(x[i-1]+ 0.5*dx, y[i-1]+ 0.5* k2);
        float k4 = dx*deriva(x[i-1]+ dx    , y[i-1]+ k3 );
        
        float mean =0;
        mean = (1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
        x[i] = x[i-1]+dx;
        y[i] = y[i-1] + mean;
        cout << x[i]<<"||"<<y[i]<<endl;
            
    }
    
    
    return 0;       
    
}