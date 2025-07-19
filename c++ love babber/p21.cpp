// Solving leetcode Questions

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> v){
    for(auto i:v){
        cout<<" "<<i;
    }
    cout<<endl;
}


// roatate an array by k
void rotateLeft(vector<int> &v,int k){
    int n = v.size();
    k = k%n;
    vector<int> a;
    int j=0;
    for(int i=0;i<k;i++){
        a.push_back(v[i]);
    }
    for(int i=k;i<n;i++){
        v[j++] = v[i];
        // v[i] = 
    }
    int m=0;
    for(int i=n-k;i<n;i++){
        v[j++] = a[m++]; 
    }
}
void rotateRight(vector<int> &v,int k){
    int n = v.size();
    k = k%n;
    k = n-k;
    vector<int> a;
    int j=n-1;
    for(int i=k;i<n;i++){
        a.push_back(v[i]);
    }
    for(int i=k-1;i>=0;i--){
        // cout<<" "<<v[i]<<endl;
        v[j--] = v[i];
        // v[i] = 
    }
    // print(v);
    // cout<<" "<<k;
    int m=0;
    for(int i=0;i<n-k;i++){
        v[i] = a[i]; 
    }
}
void rotateRight1(vector<int> &v,int k){
    int n = v.size();
    // k = k%n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[(i+k)%n] = v[i]; 
    }
    v=a;
    
}
// 1 2 3 4 5
// 5 1 2 3 4   
// 4 5 1 2 3 


// check if array is sorted or not
bool isSorted(vector<int> v){
    int pair =0;
    // for(int i=1;i<v.size();i++){
    //     if(v[i]>v[i-1]){
    //         // cout<<" "<<pair<<" "<<v[i]<<endl;
    //             if(pair==1 && v[i]>v[0]){
    //                 return false;
    //             }
    //     }else{
    //         pair++;
    //     }
    //     if(pair>1) return false;
    // }
    // return true;
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1])
            pair++;
    }
    if(v[v.size()-1]>v[0])
        pair++;
    return pair<=1;
}


vector<int> addTwoArray(vector<int> a,vector<int> b){
    vector<int> ans;
    int i=0,j=0,m=a.size(),n=b.size(),carry=0;
    while(i<m || j<n){
        int f=0,s=0;
        if(i<m) f=a[m-i-1];
        if(j<n) s=b[n-i-1];
        i++;j++;
        carry+=f+s;
        ans.push_back(carry%10);
        carry = carry/10;
    }
    if(carry) ans.push_back(carry);
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {

    vector<int> a = {1,2,3,4,5,6};
    // print(a);
    // rotateLeft(a,4);
    rotateRight1(a,7);
    a= {4,7,3,5};
    // print(a);
    // cout<<boolalpha;
    // cout<<" is sorted "<<isSorted(a);
    vector<int> a1 = {9,9},b1={9,9};
    print(addTwoArray(a1,b1));
    
    return 0;
}
