#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    float dx = 0.01;
    float v = pow(10,-8);
    float l = 1.0;
    float t0 = 0.0;
    float tf = 2500;
    float dt = (dx*0.000025)/v;
    float temp0 = 50.0;
    float tempf = 100.0;
    int puntos = l/dx;
    float deltax = pow(dx,2);
    cout<< "mi dt es: " << dt <<endl;
    cout<< "numero de puntos es: "<<puntos<<endl;
    
    float T[puntos][puntos];
    float T_fut[puntos][puntos];
    
    //Condiciones iniciales
    

    
    ofstream outfile;
    outfile.open("data.txt");
    
    //Bucle para las condiciones iniciales del enunciado
    
    for(int k =0; k<puntos; k++)
    {
        for (int j = 0; j<puntos; j++)
        {
            T[j][k] = temp0;
            if((j>=20 && j<=40) && (k>=40 && k<=60))
            {
                T[j][k] = tempf;
            }
        }        
    }
    for(int k =0; k<puntos; k++)
    {
        for (int j = 0; j<puntos; j++)
        {
            outfile << T[j][k] << " ";
        }
        outfile << "\n";
    }
    outfile.close();
    
    //Cálculo de la temperatura en el futuro (tiempo = 100s)
    float constante = v*dt/deltax;
    
    ofstream outfile1;
    outfile1.open("Tiempo0.txt");

    for(int i = 1; i <100; i+=dt)
    {
        for(int k = 1; k<puntos-1; k++)
        {
            for (int j = 1; j<puntos-1; j++)
            {
                T_fut[j][k] = constante*(T[j+1][k]+T[j-1][k]-2*T[j][k])+ constante*(T[j][k+1]+T[j][k-1]-2*T[j][k]) + T[j][k];
                T[j][k] = T_fut[j][k];                
            }
        }        
    }
    
    for (int k=0; k<puntos;k++)
    {
        for (int j = 0; j<puntos; j++)
        {
            outfile1 << T_fut[j][k] << " ";
        }
        outfile1 << "\n";
    }
    outfile1.close();
    
    
    //Calculo de la temperatura en el futuro (tiempo = 2500s)
  
    ofstream outfile2;
    outfile2.open("Temp1.txt");
    for(int i = 1; i <2500; i+=dt)
    {
        for(int k = 1; k<puntos-1; k++)
        {
            for (int j = 1; j<puntos-1; j++)
            {
                T_fut[j][k] = constante*(T[j+1][k]+T[j-1][k]-2*T[j][k])+ constante*(T[j][k+1]+T[j][k-1]-2*T[j][k]) + T[j][k];                
                T[j][k] = T_fut[j][k];
            }        
        }
    }
    for (int k=0; k<puntos;k++)
    {
        for (int j = 0; j<puntos; j++)
        {
            outfile2 << T_fut[j][k] << " ";
        }
        outfile2 << "\n";
    }
    outfile2.close();
    
    
    return 0;
}
