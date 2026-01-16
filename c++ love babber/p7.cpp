// Leetcode problem solving

#include <iostream>
#include <cmath>
using namespace std;

//  7. Reverse Integer
int reverseInteger(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (ans < -pow(2, 31) / 10 || ans > (pow(2, 31) - 1) / 10)
            return 0;
        ans = ans * 10 + digit;
        n = n / 10;
        // pow()
    }
    return ans;
}

// 1009. Complement of Base 10 Integer
int complementBase10(int n)
{
    // int ans =

    //  000000101
    //
    //        010
    //
    int num = n, ans = 0, x = 1;
    while (num != 0)
    {
        // int bit = num&1;
        ans = 1 * x + ans; //   ans = (ans<<1) | 1;  these is known as masking
        num = num >> 1;
        x *= 2;
    }
    ans = ~n & ans;
    // cout<<ans;
    return ans;
    // cout<<~n & ans;
    // while(n!=0){

    // }
}

// 231. Power of Two
// logics are very good in leetcode
bool isPowerOfTwo(int n)
{
    int ans = 0, x = 1;
    while (n > ans)
    {
        ans = 2 * x;
        if (n == ans)
            return true;
        x *= 2;
    }
    return false;
}

// Any power of two has exactly one bit set in its binary representation. For example, 8 is 1000 and 16 is 10000. If you subtract 1 from such numbers, all bits to the right of the set bit become 1, and a bitwise AND will result in zero.
// return n > 0 and (n & (n - 1)) == 0

int main()
{
    int a{-1998};
    a = {1534236469};

    cout << " testing for - mod 10 " << (-1 % 10) << endl;

    int ans = reverseInteger(a);
    cout << "Answer :- " << ans << endl;

    int b{7};
    ans = complementBase10(b);
    cout << "Complement Base 10 is " << ans << endl;

    int c{9};
    bool ans1 = isPowerOfTwo(c);
    cout << boolalpha;
    cout << "Is Power Of Two " << ans1;
    return 0;
}
