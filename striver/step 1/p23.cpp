// Print N to 1 without loop


#include <iostream>
using namespace std;

void printNos(int N) {
    // code here
    if(N==0) return;
    cout<<N<<" ";
    printNos(N-1);
}

int main() {
    
    return 0;
}
