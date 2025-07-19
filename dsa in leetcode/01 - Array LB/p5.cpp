// Arranage all positive numberse after negative numbers . without maintaining order

// quick sort partition for maintaining order


#include <iostream>
using namespace std;



// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}

int main() {
    
    return 0;
}
