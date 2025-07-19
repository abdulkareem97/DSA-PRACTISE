// Solving pattern questions part 2

#include <iostream>
using namespace std;
int main()
{
    // cout<<"hello";
    int a{4};
    int count{1};
    char ch = {'A'};
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a-i+1; j++)
        {
            // if (i + j > a)
            // {
            //     cout << "*";
            // }
            // else
            // {
            //     cout << " ";
            // }
            cout<<"*";
            

        }
        cout<<endl;
    }
    return 0;
}