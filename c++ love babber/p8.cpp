// Switch statement and functions

#include <iostream>
using namespace std;

bool isEven(int n)
{
    return !n & 1;
}

int ap(int n)
{
    return 3 * n + 7;
}

int countBit(int a, int b)
{
    int count = 0;
    while (a != 0)
    {
        if (a & 1)
        {
            count++;
        }
        a = a >> 1;
    }
    while (b != 0)
    {
        if (b & 1)
        {
            count++;
        }
        b = b >> 1;
    }
    return count;
}

int fib(int n)
{
    int n1 = 0, n2 = 1, ans = 0;
    if (n < 2)
    {
        return n;
    }
    for (int i = 1; i < n; i++)
    {
        ans = n1 + n2;
        n1 = n2;
        n2 = ans;
    }
    return ans;
}

int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

int nCr(int n, int r)
{

    int num = fact(n);
    int deno = fact(r) * fact(n - r);
    return num / deno;
}

// counting 1-n , isPrime

// Function call stack
//  pass by value , pass by reference

int main()
{
    // switch and functions
    // int a,b;
    // cout<<"Enter The Value of a :- ";
    // cin>>a;
    // cout<<"Enter The Value of b :- ";
    // cin>>b;
    // cout<<"Enter The Operator :- ";
    // char op;
    // cin>>op;
    // int ans =0;

    // switch (op)
    // {
    // case '+':
    //     ans = a+b;
    //     break;
    // case '-':
    //     ans = a-b;
    //     break;
    // case '/':
    //     ans = a/b;
    //     break;
    // case '*':
    //     ans = a*b;
    //     break;

    // default:
    //     break;
    // }
    // cout<<ans;

    // int z {1340};
    // int n100 = z/100;
    // z=z%100;
    // int n50 = z/50;
    // z=z%50;
    // int n20 = z/20;
    // z=z%20;
    // int n1 = z/1;
    // z=z%1;

    // cout<<"100 notes "<<n100<<" 50 notes "<<n50<<" 20 notes "<<n20<<" 1 notes "<<n1<<" remaining "<<z;

    cout << boolalpha;
    // cout<<isEven(6);
    // cout<<ap(3);
    // cout<<countBit(3,1);
    for (size_t i = 0; i < 10; i++)
    {
        cout << fib(i) << " ";
    }

    cout << endl
         << " ncr of 4 and 2 " << nCr(8, 2);
    return 0;
}
