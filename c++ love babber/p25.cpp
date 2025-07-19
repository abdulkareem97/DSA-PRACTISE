// Pointers

#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int *p = &a;
    cout << (*p) << " Address " << p << endl;
    int b[] = {10, 20, 30};
    int *q = b;
    cout << *(q + 1) << endl;
    delete p;
    p = nullptr;
    // *p = 5;
    cout << a;
    return 0;
}
