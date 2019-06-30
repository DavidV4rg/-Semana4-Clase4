#include <iostream>

using namespace std;


int main()
{
    int n = 7;
    double factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
    cout << "El factorial de 7 es: "  << factorial<< endl; 
    
    int e = 77;
    for(int i = 1; i<= e; i++){
        factorial *= i;
    }
    cout << "El factorial de 77 es: " << factorial << endl;
    return 0;
}

