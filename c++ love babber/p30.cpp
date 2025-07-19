// Macros , Global variable , inline function & default arguments

#include <iostream>

// macros
#define PI 3.143
#define min(a, b) (a < b ? a : b)
using namespace std;

// Global Variable
int x = 4;

// inline functions
inline int max(int a,int b){
    return (a>b) ? a : b;
}

void print(int *arr,int size,int start=0){

    for(int i=start;i<size;i++){
        cout<<" "<<arr[i];
    }

}

int main()
{

    cout << "PI Value is " << PI << endl;
    cout << "min value is " << min(9, 5) << endl;
    cout << " x value is " << x<<endl;
    cout << " max value is "<<max(10,5) << endl;
    int a[] = {1,2,3,4};
    print(a,4,3);
    return 0;
}
