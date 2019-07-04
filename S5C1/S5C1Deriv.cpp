#include <iostream>
#include <math.h> 

using namespace std;

double derivada( int Tamañ, float delta, float ar1[], float ar2[])
{
    float *deriva;
    deriva = new float [Tamañ];            
    for (int i =0; i <=Tamañ; i++)
    {       
        deriva = (ar1[i+1] - ar1[i])/ delta;
        cout << deriva[i] << endl;        
    }
    return 0;
    
}

int main()
{
    double a;
    double b;
    int N;
    cout << "Ingrese un número "; cin >> a;
    cout << "Ingrese otro número "; cin >> b;
    cout << "Ingrese el número de puntos "; cin >> N;
    float dx = (b-a)/(N-1);
    float *arr1;
    arr1 = new float [N];        
    arr1[0]=a;
    arr1[N]=b;
    float *arr2;
    arr2 = new float [N];
    for (int i = 1; i <= N-1; i++)
    {        
        arr1[i] = a + i*dx;
        cout << arr1[i] << endl;
    }
    for (int i = 0; i <=N; i++){
        arr2[i] = cos(arr1[i]);
        cout << arr2[i] << endl;
    }
    
    cout << derivada(N, dx, arr2, arr1)<< endl;
    
    return 0;
}




                             



    
        
        
