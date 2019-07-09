#include <iostream>
#include <fstream>

using namespace std;

/*
void cuerda(float u_pa, float u_fu, float ti);

void cuerda(float u_pa, float u_fu, float ti)
{
}
*/

int main()
{
    float dx = 0.005;
    int N_puntos = 120;
    int c = 300;
    float dt = (dx*0.25)/c;
    float tf = 0.1;
    float t0 = 0;
    int puntos = (tf-t0)/N_puntos;
    float t[N_puntos];
    float u_past[N_puntos];
    float u_future[N_puntos];
    t[0] = 0;
    t[N_puntos] = 0.1;
    
    ofstream outfile;
    outfile.open("datos.dat");
    for (int i = 1; i<= N_puntos; i++)
    {
       t[i] = t[i-1]+dt;
    
        outfile << t[i-1] << endl;
    }
    
        
    
    
    return 0;
}
