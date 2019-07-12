#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    float dx = 0.01;
    float v = pow(10,-4);
    float l = 1.0;
    float t0 = 0.0;
    float tf = 2500;
    float dt = 0.05;
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

    for(float i = 0; i <100; i+=dt)
    {
        for(int j = 1; j<puntos-1; j++)
        {
            for (int k = 1; k<puntos-1; k++)
            {
                T_fut[k][j] = constante*(T[k+1][j]+T[k-1][j]-2*T[k][j])+ constante*(T[k][j+1]+T[k][j-1]-2*T[k][j]) + T[k][j];
                T[k][j] = T_fut[k][j];                
            }
        }        
    }
    
    for (int j=0; j<puntos;j++)
    {
        for (int k = 0; k<puntos; k++)
        {
            outfile1 << T[k][j] << " ";
        }
        outfile1 << "\n";
    }
    outfile1.close();
    
    
    //Calculo de la temperatura en el futuro (tiempo = 2500s)
  
    ofstream outfile2;
    outfile2.open("Temp1.txt");
    for(float i = 0; i <2500; i+=dt)
    {
        for(int j = 1; j<puntos-1; j++)
        {
            for (int k = 1; k<puntos-1; k++)
            {
                T_fut[k][j] = constante*(T[k+1][j]+T[k-1][j]-2*T[k][j])+ constante*(T[k][j+1]+T[k][j-1]-2*T[k][j]) + T[k][j];               
                T[k][j] = T_fut[k][j];
            }        
        }
    }
    for (int j=0; j<puntos;j++)
    {
        for (int k = 0; k<puntos; k++)
        {
            outfile2 << T[k][j] << " ";
        }
        outfile2 << "\n";
    }
    outfile2.close();
    
    
    return 0;
}
