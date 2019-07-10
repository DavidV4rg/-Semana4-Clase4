#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int main()
{
    
    float dx = 0.005;
    float c = 300;
    float l = 1.0;
    float A0 = 0.1;
    int N_puntos = (l/dx)+1;
    float dt = (dx*0.9)/c;
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
    outfile.open("inicia.dat");
    //Condiciones iniciales
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
        outfile << t[i-1] << ";" << xpast[i-1]<<endl;
    }
    outfile.close();
    //Primer paso
    
    ofstream outfile2;
    outfile2.open("primer.dat");
        
    for (int i = 0; i <=N_puntos; i++)
    {
        xpres[i] = (r/2)*(xpast[i+1]+xpast[i-1]-2*xpast[i]) + xpast[i]; 
        outfile2 << xpres[i]<< endl;
    }
    outfile2.close();
    
    //Siguientes pasos
    int contador = 0;
    ofstream outfile1;
    outfile1.open("data.dat");
    for (int i = 0; i<=N_puntos; i++)
    {
        contador = contador+1;
        for (int k = 1; k<N_puntos; k++)
        {
            xfutu[k]= r*(xpres[k+1]+xpres[k-1]-2*xpres[k])-xpast[k]+2*xpres[k];
            
            if(contador%100==0)
            {
                outfile << t[k-1] <<";" << xfutu[k-1] <<endl;
            }
        }
            
            for(int z =1; z<N_puntos; z++)
            {
                xpast[z] = xpres[z];
                xpres[z] = xfutu[z]; 
            } 
        

               
    }
    outfile1.close();

    return 0;
}
