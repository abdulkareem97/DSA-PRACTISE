#include<iostream>
using namespace std;


int main(){
    int n{4};
    int ans = 1;
    while(n){
        ans *= n;
        n--;
    }
    cout<<ans;

    // continue and breaak statment

    for(int i=0;i<10;i++){
        if(i==5) break;
        cout<<" "<<i;
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        if(i==5) continue;
        cout<<" "<<i;
    }
}