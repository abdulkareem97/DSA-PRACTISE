// Reverse the array

#include <iostream>
using namespace std;


void reverse(int arr[],int size){
    int s=0,e=size-1;
    while(s<e){
        swap(arr[s++],arr[e--]);
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    reverse(arr,10);

    for(auto i:arr){
        cout<< " "<<i;
    }
    
    return 0;
}
