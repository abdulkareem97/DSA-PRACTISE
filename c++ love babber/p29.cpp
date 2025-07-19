//  dynamic memory allocation

#include <iostream>
using namespace std;

int main()
{

    // creating 2D array
    int **ptr = new int*[5];
    for(int i=0 ; i<5 ; i++){
        ptr[i] = new int[5]{i};
    }

    for(int i=0 ; i<5 ;i ++){
        for(int j=0;j<5;j++){
            cout << ptr[i][j] << " ";
        }
        cout << endl ;
    }

    for( int i=0; i<5 ; i++){
        delete[] ptr[i];
    }
    delete[] ptr;




    // int arr[5] = {1, 2, 3, 4, 5};
    // error
    // cout << arr[0][1];

    cout << " end ";
    return 0;
}
