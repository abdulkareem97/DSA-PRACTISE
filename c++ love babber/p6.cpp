// Binary to decimal number system

#include <iostream>
using namespace std;

int decimalToBinary(int n){
    int ans = 0,x=1;
    while(n!=0){
        int bit = n&1;
        ans = bit*x + ans;
        x*=10;
        n = n>>1;
    }
    return ans;
}
int decimalToBinary1(int n){
    
    int ans = 0,x=1;
    while(n!=0){
        int bit = n%2;
        ans = bit*x+ans;
        x*=10;
        n = n/2;
    }
    return ans;
}
int decimalToBinaryNegative(int n){
    
    int ans = 0,x=1,carry=1;
 
    while(n!=0){
        int bit = n%2;
        bit = !bit;
        int temp = bit;
        bit = (bit+carry)%2;
        carry = (temp+carry)/2;
        // cout<<bit<<carry<<endl;
        
        ans = bit*x+ans;
        x*=10;
        n = n/2;
    }
    return ans;
}

// 110
// 001
//  +1
// 010


// 110
// 001
// 110


int binaryToDecimal(int n){
    int ans = 0,x=1;

    while(n!=0){
        int bit = n%10;
        ans = bit*x+ans;
        x*=2;
        n=n/10;
    }
    return ans;
}



int main() {
    int a {34};

    // cout<<"Decimal To binary "<<endl;
    // int ans = decimalToBinary(a);
    // cout<<ans<<endl;
    // int ans1 = decimalToBinary1(a);
    // cout<<ans1<<endl;


    // int b {-8};
    // int neg = {-b};
    // cout<<neg<<endl;
    // cout<<"Negative Number To Decimal"<<endl;
    // int ans2 = decimalToBinaryNegative(neg);
    // cout<<ans2<<endl;

    int binary = 1101;
    int ans3 = binaryToDecimal(binary);
    cout<<ans3<<endl;
    return 0;
}
