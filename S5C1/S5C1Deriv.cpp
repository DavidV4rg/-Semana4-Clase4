#include <iostream>
#include <math.h> 

using namespace std;



int main()
{
    int a;
    int b;
    int N;
    cout << "Ingrese un número";
    cout << "Ingrese otro número";
    cout << "Ingrese el número de puntos";
    cin >> a;
    cin >> b;
    cin >> N;
    double dx = (b-a)/(N-1);
    int arr1[N];
    float arr2[N];
        
    for (int i = a; i <= N; i++)
    {
        arr1 += i;
    }
    for (int i = a; i<= N; i++)
    {
        arr2 = cos arr1[i];
    }
    return 0;
}
                             



    
        
        
