#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    double dx = 0.01;
    //MIRAR LAS UNIDADES DE ESTE COEFICIENTE
    double v = pow(10,-4);
    double lon = 1.0;
    double tiein = 0.0;
    double tifin = 2500;
    double dt = (dx*0.25)/v;
    double tempin = 50.0;
    double temp = 100.0;
    int puntos = lon/dx;
    float delta = pow(dx,2);
    
    float T[puntos][puntos];
    float T_fu[puntos][puntos];
    float time[puntos];  
    time[0] = 0;
    time[puntos] = 2500;
    T[0][0] = tiein;
    
    ofstream outfile;
    outfile.open("data.txt");
    
    //Arreglo del tiempo de 0 a 2500 segundos
    for (int i = 1; i <puntos; i++)
    {
        time[i] = time[i-1] + dt;        
    }
    //Arreglo de las condiciones iniciales
    
    for (int k = 0; k < puntos; k ++)
    {
        for (int j = 0; j <puntos; j++)
        {
            T[j][k] = tempin;
            if((j>= 20 && j <=40) && (k >=40 && k <= 60))
            {
                T[j][k] = temp;               
            }
        }       
    }
    for (int k = 0; k < puntos; k ++)
    {
        for (int j = 0; j <puntos; j++)
        {
            outfile << T[j][k] << " ";
        }
        outfile << "\n";
    }  
    outfile.close();
    
    //metodo
    /*
    ofstream outfile1;
    outfile1.open("t0.txt");
    ofstream outfile2;
    outfile1.open("t1.tx");
    ofstream outfile3;
    outfile1.open("t2.txt");
    for (int k = 0; k<puntos; k++)
    {
        for (int j = 0; j<puntos; j++)
        {
            T_fu[j][k] = (v/(dt))*((T[j+1][k]+T[j-1][k]-2*T[j][k])/delta + T[j][k+1]+T[j][k-1] -2*T[j][k]/ delta) + T[j][k];            
            for (int i = 1; i <puntos; i++)
            {
                time[i] = time[i-1] + dt;
                
                if(time[i] == 0)
                {
                    outfile1 << T_fu[j][k]<< " "; 
                }
                if (time[i] == 100)
                {
                    outfile2 << T_fu[j][k] << " ";
                }
                if (time[i] == 2500)
                {
                    outfile3 << T_fu[j][k]<< " ";
                } 
            }
        }
        outfile1 << "\n";
        outfile2 << "\n";
        outfile3 << "\n";
        
    }
    outfile1.close();
    outfile2.close();
    outfile3.close();
   */ 
    return 0;    
}
