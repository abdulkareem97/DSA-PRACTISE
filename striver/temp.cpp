#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    k = k % v.size();
    int temp = k;
    for (int i = 0; i < v.size(); i++)
    {
        // cout << " k " << k << endl;
        swap(v[i], v[k]);
        k++;
        if (k == v.size())
            break;
    }
    int num = v.size() - temp;
    for (int n1 = temp; n1 < v.size(); n1++)
    {
        swap(v[n1], v[num++]);
    }

    for (int ele : v)
    {
        cout << " " << ele;
    }
    cout << endl;
    return 0;
}
