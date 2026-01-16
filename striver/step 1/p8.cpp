// Functions | Pass by value and pass by reference

#include <iostream>
using namespace std;

// pass by value and pass by refereancee
void passByValue(int x)
{
    x = x + 2;
    cout << x << endl;
}
void passByRef(int &x)
{
    x = x + 2;
    cout << x << endl;
}

int main()
{
    int x{7};

    cout << " in main " << x << endl;
    passByValue(x);
    cout << " in main " << x << endl;
    passByRef(x);
    cout << " in main " << x << endl;

    return 0;
}
