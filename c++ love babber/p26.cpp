//  pointers

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30};

    cout<< * (arr+1) << endl ;

    // arr[i]  = * (arr+i)
    int i=0;

    i[arr] = * (arr + i);
    cout << i[arr] << endl ;
    cout << arr << endl ;


    //  cout behave differently for char pointer

    char carr[] = "abcde";
    cout << carr << endl ;
    char *ch = carr;
    cout << ch << endl;
    return 0;
}
