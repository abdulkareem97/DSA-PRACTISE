// Convert a sentence into its equivalent mobile numeric keypad sequence
// Difficulty: EasyAccuracy: 45.52%Submissions: 36K+Points: 2
// Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence. Please note there might be spaces in between the words in a sentence and we can print spaces by pressing 0.



 

// Example 1:

// Input:
// S = "GFG"
// Output: 43334
// Explanation: For 'G' press '4' one time.
// For 'F' press '3' three times.
// Example 2:

// Input:
// S = "HEY U"
// Output: 4433999088
// Explanation: For 'H' press '4' two times.
// For 'E' press '3' two times. For 'Y' press '9' 
// three times. For white space press '0' one time.
// For 'U' press '8' two times.


#include <iostream>
#include<unordered_map>
using namespace std;


string printSequence(string S)
{
    //code here.
    unordered_map<char,string> m;
    int v = 2,nums=0;
    m[' '] = "0";
    for(int i='A';i<='Z';i++){
        m[i] =  string(nums+1,v+'0');;
        nums++;
        if(i!='R' && i!='Y' && nums>=3){
            v++;
            nums=0;
        }
    }
    string ans;
    for(char c:S){
        
        ans += m[c];
    }
    return ans;
}

int main() {
    
    return 0;
}
