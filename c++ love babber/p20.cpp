// Solving Leetcode Questions

#include <iostream>
#include<vector>

// #define  vec vector<int>

// #define a 4;
using namespace std;
void printArray(vector<int> v){
    // cout<<endl;
    for(auto i:v){
        cout<<" "<<i;
    }
    cout<<endl;
}



// Reverse an array
void reverseArray(vector<int> &v){
    int n=v.size();
    for(int i=0;i<n/2;i++){
        swap(v[i],v[n-i-1]);
    }
}

// Reverse an array after mth index
void reverseAfterM(vector<int> &v,int m){
    int s=m+1,e=v.size()-1;
    while(s<e){
        swap(v[s],v[e]);
        s++;e--;
    }
}

// merge two sorted array
vector<int> mergeSortedArray(vector<int> a,vector<int> b){
        vector<int> c;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]) {
                c.push_back(a[i++]);
            }
            else{
                c.push_back(b[j++]);
            }
        }
        while(i<a.size()){
            c.push_back(a[i++]);
        }
        while(j<b.size()){
            c.push_back(b[j++]);
        }
        return c;

}

// merge two sorted array in one array
void mergeInOne(vector<int> &a,int m,vector<int> b,int n){
    int s = a.size();
    m--;n--;
    // cout<<" hello";
    for(int i=s-1;i>=0 && n>=0;i--){
        
        // cout<<" "<<a[m]<<" "<<b[n]<<
        if(m>=0 && a[m]>b[n]) a[i]=a[m--];
        else a[i]=b[n--];
        // cout<<" "<<a[0];
    }
    cout<<endl;

}


// Moves Zeros To end
void moveZero(vector<int> &a){
    // int j=0;
    // for(int i=0;i<a.size();i++){
    //     if(a[i]==0){
    //         // j=i;
    //     }else{
    //         swap(a[i],a[j]);
    //         j=i;
    //     }
    //     // printArray(a);
    // }

    int nonZero = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]){
            swap(a[nonZero],a[i]);
            nonZero++;
        }
    }
}





int main() {
    vector<int> v = {1,2,3,4,5,6};
    v = {10,20,30,40,50 ,60,70}; 
    // reverseArray(v);
    // printArray(v);
    int m = 3;
    // reverseAfterM(v,m);
    // printArray(v);

    vector<int> a={1,3,5,9},b={2,4};
    // printArray(mergeSortedArray(a,b));

    a = {1,3,5,9,0,0,0} , b= {50,60,70};
    a = {10,20,30,40,0,0,0}, b = {1,2,3};
    mergeInOne(a,4,b,b.size());
    printArray(a);

    a = {0,3,1,0,2,0};
    // a = {1,2,3,0,4};
    // moveZero(a);
    // printArray(a);

    return 0;
}
