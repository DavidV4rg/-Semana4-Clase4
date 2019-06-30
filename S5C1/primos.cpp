#include <iostream>
#include <math.h> 

using namespace std;

int main(){
    
    int i;
    int b;
    
    cout << "Ingrese un número entero ";
    cin >> i;
    cout << "Ingrese un segundo número entero";
    cin >> b;
    
    for (i ; i<= b; i++)
        for (int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
                break;
            else if(j+1 > sqrt(i) )
            {
                cout << "Los numeros primos en su intervalo son: "<< i <<endl;
            }
        }
    return 0;
}