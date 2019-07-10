#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    
    float dx = 0.0005;
    float c = 300;
    int N_puntos = 42;
    float dt = 0.1/N_puntos;
    
    float t[N_puntos];
    float x_past[N_puntos];
    float x_fut[N_puntos];    
    t[0]=0;
    t[N_puntos] = 0.1;
    x_past[0] = 0;
    x_past[N_puntos] = 0;
    
    ofstream outfile;
    outfile.open("data.dat");
    
    for (int i = 1; i<=N_puntos; i++)
    {
        t[i] = t[i-1]+dt;
        
        if(t[i]<0.05)
        {
            x_past[i]= x_past[i-1]+dx;
        }
        
        else if(t[i]>0.05)
        {
            x_past[i]= x_past[i-1]-dx;
        }
        
        outfile << t[i-1] << ";" << x_past[i-1] << endl;
        
        
    }
    outfile.close();
        
    return 0;
}
