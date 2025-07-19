// Double Pointers

#include <iostream>
using namespace std;

// null pointer cant assign value

// int *p = a
//  p[2] is equal to *(p+2)

int main() {
    int a = 5;
    int *p = &a;
    cout<< *p << endl;
    int **q = &p;
    // int **
    int ***z = &q;
    cout<< &q << endl ;

    cout<< " End ";
    return 0;
}
