// Binary Search
/*
Elemenst should be in monotonic functions
monotonic - arrange in increasing or decreasing order

*/
#include <iostream>
using namespace std;


/*
there is a problem 
when calculating mid value it can go out of range of int
i.e  left+right    if left = 10^31  and right 10^31+1
so we can use formula = left/2 + right/2 
                         = left  - left/2 + right/2
                         =  left + right/2 - left/2
                         = left + (right-left)/2


*/
int binarySearch(int arr[],int size,int key){
    int left=0,right=size-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[],int size,int key,int left,int right){
    int index = -1;
    if(left<=right){
         int mid = (left+right)/2;
        //  cout<<mid<<endl;
         if(arr[mid]==key) return mid;
          else if(arr[mid]<key){
                index = recursiveBinarySearch(arr,size,key,mid+1,right);
          }else{
            index = recursiveBinarySearch(arr,size,key,left,mid-1);
          }
    }
    return index;
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"ELement Found At Index "<<binarySearch(arr,size,1)<<endl;
    cout<<"ELement Found At Index "<<recursiveBinarySearch(arr,size,2,0,size-1)<<endl;
    return 0;
}
