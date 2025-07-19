// Recursion

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int fib(int f)
{
    if (f < 2)
        return f;
    return fib(f - 1) + fib(f - 2);
}


//  Count Ways To Reach The N-th Stairs - cn
int countDistinctWays(int nStairs) {
    //  Write your code here.
    int ans = 0;
    if(nStairs==0){
        return 1;
    }
    if(nStairs < 0){
        return 0;
    }
    ans = countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
    return ans;
}


int rec(int n,unordered_map<int,int> m={}){
        m[n] = 4;
        cout << m[n];
}


void sayDigit(int x){
    // static int n = 10;
    if(x<=0) return;

    int y = x%10;
    sayDigit(x/10);
    cout << y <<  " ";

}



int main()
{
    int f = 4;
    // cout << " Fib of " << f << " is " << fib(f);
    // cout << " To reach nth floor with either two or one ways are "<<countDistinctWays(5);
    // rec(4);
    sayDigit(412);
    return 0;
}
