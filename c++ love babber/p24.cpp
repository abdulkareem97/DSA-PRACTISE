// Maths for dsa

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Find Prime number using Sieve method
// GCD/LCM or Euclid’s Algo 
// Modular Arithmetics/ Fast Exponentiation

// Home work i will do it later
// pigeon hole principle
// catalon number
// inclusive / exclusive principle (inclusion)



// 204. Count Primes
// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

// Conquer the Prime Count – Master the Sieve of Eratosthenes Trick!
int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> prime(n + 1, true);

    for (long long i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (long long j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return cnt;
}


// Euclids algorithm gcd
// gcd * lcm = a*b
int gcd(int a , int b){
    while(a!=b){
        // cout<<a<<" "<<b<<endl;
        if(!a || !b){
            return a | b;
        }
        if(a<b){
            b = b%a;
        }else{
            a = a%b;
        }
    }
    return a;
}

// Problem statement
// You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'.
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int res = 1;
	while(n){
		if(n&1) res = (1LL * res * x)%m;
		 x = (1LL * x * x)%m;
		n = n>>1;
	}
	return res;
}


int pow(int a,int b){
    if(b==0) return 1;
    int res = pow(a,b>>1);
    if(b&1)
        return res * res * a;
    return res * res;
}


// "Basic" arithmetic
// First off, some important identities about the modulo operator:

// (a%m)+(b%m) = (a+b)%m
// (a%m)-(b%m) = (a-b)%m
// (a%m)*(b%m) = (a*b)%m



int main()
{

    cout<< gcd(4,6) <<endl;
    cout<< pow(2,3) <<endl;
    // cout<< pow(2,6) <<endl;
    return 0;
}
