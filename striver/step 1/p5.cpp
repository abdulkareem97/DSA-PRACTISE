// What are array , string?
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    string s = "hello";
    cout << s << endl;

    string s2 = "hello";

    string s3 = "hell1";

    cout << boolalpha << (s == s2) << " " << (s2 == s3);
    return 0;
}
