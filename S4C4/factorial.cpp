#include <iostream>

using namespace std;


int main()
{
    int n;
    int factorial = 1;
    cout << "Ingrese un numero: ";
    cin >> n;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
    cout << "El factorial es "  << factorial<< endl;    
    return 0;
}