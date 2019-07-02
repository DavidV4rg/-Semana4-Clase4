#include <iostream>
#include <math.h> 

using namespace std;



int prod(int arr1[5], int arr2[5])
{
    
    for (int i = 0; i<=4; i++)
    {
        cout<<"El producto de los dos arreglos es: "<<arr1[i]*arr2[i]<<endl;
    }
    return 0;
}

int punt(int arr1[5], int arr2[5])
{
    int v = 0;
    for (int i =0; i <=4; i++)
    {        
        v = v + (arr1[i]*arr2[i]);        
    }
    
    return v;
}
    
   
int main()
{
    int a[5] = {1,2,3,4,5};
    int b[5] = {10,20,30,40,50};
    
    prod(a, b);
    cout << "El producto punto de los arreglos es: "<< punt(a,b) <<endl;
    return 0;
}

        
    

