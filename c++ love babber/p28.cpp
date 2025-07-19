// Referance Variabel

#include <iostream>
using namespace std;

// int& timePass(){
//     int ans = 5;
//     return ans;
// }
int* timePass2(int n){
    int *p = &n;
    return p;
}

int main() {
    int a = 4;
    int &b = a;
    a++;
    // b++;
    // cout << b << " " << a << endl ;


    // dont do this 
    // int ptr = timePass();
    // cout << ptr ;

    // it works but dangerous
    int *ptr = timePass2(a);
    // cout<< *ptr << endl;

    int n = 0;
    // cin >> n;
    int arr[n] = {};
    cout << arr[0] << endl;


    // Create variable in heap value
    // dynamic memory location
    int *a1 = new int(5);

    cout << *a1 << endl;
    
    int *arr1 = new int[5]{10,20,30,40,50};

    cout << 4[arr1] << endl ;

    // use delete keyword to remove space;
    delete []arr1;

    cout << "end ";
    return 0;
}
