// 58. Length of Last Word

// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.

var lengthOfLastWord = function(s) {
    let x = '',n=s.length
    for(let i=s.length-1;i>=0;i--){
        if(s[i]==' '){
            n--
        }else{
            break
        }
    }
    let word = '',c=0
    for(let i=0;i<n;i++){
        // word+=s[i]
        c++
        if(s[i]==' ') c=0
    }
    return c
};

// class Solution {
//     public:
//         int lengthOfLastWord(string s) {
//             int siz=s.size(),kount=0,flag=0;
//             for(int i=siz-1;i>=0;i--){
//                 if(s[i]==' '&&flag)break;
//                 if(s[i]!=' '){
//                     flag=1;
//                     kount++;
//                 }
//             }
//             return kount;
//         }
//     };