#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    string s= "hello";
    cout<<s;
    return 0;
}
