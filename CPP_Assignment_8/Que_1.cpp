#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n<0)
    {
        throw 2;
    }
    
        int result=1;
        for(int i=1;i<=n;i++)
        {
            result = result*i;
        }
        cout<<"Factorial : "<<result<<endl;
    
}

int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    try
    {
        factorial(n);
    }
    catch(int error)
    {
        cout<<"For factorial number must be greater than zero"<<endl;
    }

    return 0;
}