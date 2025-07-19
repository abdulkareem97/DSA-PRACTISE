// Print 1 To N Without Loop
// Difficulty: BasicAccuracy: 61.33%Submissions: 286K+Points: 1
// Print numbers from 1 to n without the help of loops. You only need to complete the function printNos() that takes n as a parameter and prints the number from 1 to n recursively.

// Note: Don't print any newline, it will be added by the driver code.

// Examples:

// Input: n = 10
// Output: 1 2 3 4 5 6 7 8 9 10
// Input: n = 5
// Output: 1 2 3 4 5
// Input: n = 1
// Output: 1

#include <iostream>
using namespace std;

void printNos(int n) {
    // Your code here
    if(n==0) return;
    printNos(n-1);
    cout<<n<<" ";
}

int main() {
    
    return 0;
}
