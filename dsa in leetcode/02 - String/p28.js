// 1945. Sum of Digits of String After Convert

// You are given a string s consisting of lowercase English letters, and an integer k. Your task is to convert the string into an integer by a special process, and then transform it by summing its digits repeatedly k times. More specifically, perform the following steps:

// Convert s into an integer by replacing each letter with its position in the alphabet (i.e. replace 'a' with 1, 'b' with 2, ..., 'z' with 26).
// Transform the integer by replacing it with the sum of its digits.
// Repeat the transform operation (step 2) k times in total.
// For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

// Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
// Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
// Transform #2: 17 ➝ 1 + 7 ➝ 8
// Return the resulting integer after performing the operations described above.

 

// Example 1:

// Input: s = "iiii", k = 1

// Output: 36

// Explanation:

// The operations are as follows:
// - Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
// - Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
// Thus the resulting integer is 36.

// Example 2:

// Input: s = "leetcode", k = 2

// Output: 6

// Explanation:

// The operations are as follows:
// - Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
// - Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
// - Transform #2: 33 ➝ 3 + 3 ➝ 6
// Thus the resulting integer is 6.

// Example 3:

// Input: s = "zbax", k = 2

// Output: 8

var getLucky = function(s, k) {
    let t = ''
    for(let i=0;i<s.length;i++){
        let val = s.charCodeAt(i)-'a'.charCodeAt(0) + 1
        t+=val
    // console.log(t,val)
    }
    console.log(t)
    let sum = 0
    for(let i=0;i<k;i++){
        sum=0
        for(let i=0;i<t.length;i++){
            sum+=t[i]-'0'
            // console.log(sum,i,i-'0')
        }
        t = sum.toString()
    }
    return sum
};

// class Solution {
//     public:
//         int getLucky(string s, int k) {
//             // Convert the string to a number by summing digit values
//             int currentNumber = 0;
//             for (char ch : s) {
//                 int position = ch - 'a' + 1;
//                 while (position > 0) {
//                     currentNumber += position % 10;
//                     position /= 10;
//                 }
//             }
    
//             // Apply digit sum transformations k-1 times
//             for (int i = 1; i < k; ++i) {
//                 int digitSum = 0;
//                 while (currentNumber > 0) {
//                     digitSum += currentNumber % 10;
//                     currentNumber /= 10;
//                 }
//                 currentNumber = digitSum;
    
//                 // Break early if the current number becomes less than 10
//                 if (currentNumber < 10) {
//                     break;
//                 }
//             }
    
//             return currentNumber;
//         }
//     };