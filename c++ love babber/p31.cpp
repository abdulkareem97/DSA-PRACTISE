// Recursion

#include <iostream>
using namespace std;

int power(int x, int n)
{
    if(n==1) return x;
    return x*power(x,n-1);
}

int fact(int f){
    if(f==1) return f;

    return f*fact(f-1);
}

int main()
{
    int x = 2, n = 4;

    cout << " power of two is " << power(x, n) <<endl;

    int f =4;

    cout << " Factorial of " << f << " is "<<fact(f);

    return 0;
}
