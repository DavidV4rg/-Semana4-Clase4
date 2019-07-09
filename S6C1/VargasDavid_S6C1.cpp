#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("datos.dat");
    int n_x = 80;
    int n_t = 200;
    float dx = 0.01;
    int v = 1.0;
    float dt = (dx/v)*0.25;
    int n_puntos = (2.0-0.0)/dx;
    float amp[n_puntos];
    float tiempo[n_puntos];
    tiempo[0]=0;
    tiempo[n_puntos] = 2.0;
    amp[0]= 1;
    amp[n_puntos] = 1.0;
    float t[n_puntos];
    
    
    
    for (int i = 1; i <=n_puntos; i++)
    {
        tiempo[i] = tiempo[i-1] + dx;
        amp[i] = 1.0;
        if (tiempo[i]>=0.75 && tiempo[i]<=1.25)
        {
            amp[i] = 2.0;
        }
        t[n_puntos] = tiempo[i-1];
        
        outfile << tiempo[i-1] << ";" <<amp[i-1] << endl;
    }
    
    outfile.close();
    
    outfile.open("datos1.dat");
    for(int n = 0; n<=n_t; n++)
    {
        float amp_past[n_puntos];
        amp_past[n] = 1.0;
        if(tiempo[n] >= 0.75 && tiempo[n]<=1.25)
        {
            amp_past[n]=2.0;
        }
                
        for(int i = 1; i <= n_x -1; i++)
        {
        amp[i] = amp_past[i] - (v*dt)/dx*(amp_past[i]- amp_past[i-1]);
        outfile << t[i-1] << ";" <<amp[i-1] << endl;       
        }
        
    }
    outfile.close();
    
    return 0;
    
}
