#include <iostream>
using namespace std;

class TimePass
{
    int val;

public:
    void setVal(int x)
    {
        this->val = x;
    };
    int getVal()
    {
        return this->val;
    };
};

int main()
{
    TimePass t;
    t.setVal(7);
    cout << " t.val " << t.getVal();

    return 0;
}
