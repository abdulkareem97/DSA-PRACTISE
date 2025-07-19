// 2259. Remove Digit From Number to Maximize Result
// You are given a string number representing a positive integer and a character digit.

// Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

 

// Example 1:

// Input: number = "123", digit = "3"
// Output: "12"
// Explanation: There is only one '3' in "123". After removing '3', the result is "12".
// Example 2:

// Input: number = "1231", digit = "1"
// Output: "231"
// Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
// Since 231 > 123, we return "231".
// Example 3:

// Input: number = "551", digit = "5"
// Output: "51"
// Explanation: We can remove either the first or second '5' from "551".
// Both result in the string "51".

var removeDigit = function(number, digit) {
    // let nums = []
    let found = number.length-1
    for(let i=0;i<number.length-1;i++){
        if(number[i]==digit){
            found = i
        }
        if( number[i].charCodeAt(0) == number[i+1].charCodeAt(0)){
            continue
        }
        if(number[i]==digit && number[i].charCodeAt(0) < number[i+1].charCodeAt(0)){
            let t = number.slice(0,i)+number.slice(i+1,number.length)
            return t
        }
    }
    if(number[number.length-1]==digit){
        return number.slice(0,number.length-1)
    }
    return number.slice(0,found)+number.slice(found+1,number.length)
    
};

// var removeDigit = function(number, digit) {
//     let num = String(number);
//     let max = "";

//     // Iterate through the string and try to remove each occurrence of the digit
//     for (let i = 0; i < num.length - 1; i++) {
//         if (num[i] === digit && num[i] < num[i + 1]) {
//             // Remove the current digit if it's smaller than the next one to maximize the number
//             max = num.slice(0, i) + num.slice(i + 1);
//             return max;
//         }
//     }

//     // If no such digit was found, remove the last occurrence of the digit
//     max = num.slice(0, num.lastIndexOf(digit)) + num.slice(num.lastIndexOf(digit) + 1);
//     return max;
// };