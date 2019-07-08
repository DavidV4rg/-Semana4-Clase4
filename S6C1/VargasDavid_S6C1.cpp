#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("datos.dat");
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
    float amp_past[n_puntos];
    
    
    for (int i = 1; i <=n_puntos; i++)
    {
        tiempo[i] = tiempo[i-1] + dx;
        amp[i] = 1.0;
        if (tiempo[i]>=0.75 && tiempo[i]<=1.25)
        {
            amp[i] = 2.0;
        }
        
        outfile << tiempo[i-1] << ";" <<amp[i-1] << endl;
    }
    
    outfile.close();
    
    outfile.open("datos1.dat");
    for(int i = 1; i<=n_puntos; i++)
    {
        amp_past[i] = 1.0;
        if (tiempo[i]>=0.75 && tiempo[i]<=1.25)
        {
            amp_past[i] = 2.0;
        }

        tiempo[i] = tiempo[i-1] + dx;
        amp[i] = amp_past[i] - (v*dt)/dx*(amp_past[i]- amp_past[i-1]);
        outfile << tiempo[i-1] << ";" <<amp[i-1] << endl;            
    }
    outfile.close();
    
    return 0;
    
}
