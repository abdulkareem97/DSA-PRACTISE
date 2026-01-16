// bitwise operators
//  -- for loop , continue , scope of variable
//  -- leetcode first and second question

#include <iostream>
using namespace std;

int main()
{
    // and or not xor (<< leftshift) (>> rightshift)

    // for loop
    // sum 1 to n
    int sum{0};
    for (int i = 1; i < 11; i++)
    {
        sum += i;
    }
    cout << " sum of 1 to n " << sum;

    // fib series
    int a{0}, b{1};
    cout << " " << a << " " << b;
    for (int i = 1; i < 10; i++)
    {
        cout << " " << (a + b);
        int temp = a;
        a = b;
        b = temp + b;
    }

    //  Prime Number
    int n{11};
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << " not a pime ";
            break;
        }
    }

    // contine

    //  variable and scope

    // leetcode problem - product and sum of digits

    int n1{1234}, sumOfDigit = 0, productOfDigit = 1;
    for (int i = n1; i > 0; i /= 10)
    {
        int d = i % 10;
        sumOfDigit += d;
        productOfDigit *= d;
    }
    cout << endl
         << " sum of digit " << sumOfDigit << " product of digit " << productOfDigit;

    //  leetcode second question - no of 1s in digit
    int n2{15};
    int count{0};
    while (n2)
    {
        count += n2 & 1;
        n2 = n2 >> 1;
    }
    cout << endl
         << " count " << count;

    return 0;
}
