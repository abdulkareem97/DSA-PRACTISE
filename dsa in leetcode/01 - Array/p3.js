// // 9. Palindrome Number
// Given an integer x, return true if x is a 
// palindrome
// , and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

var isPalindrome = function(x) {
    let num1=0,num2=x
    if(x<0) return false
    while(x>0){
        let val = x%10
        num1 = num1*10 +  val
        x = Math.floor(x/10)
    }
    if(num1==num2) return true
    return false
    
};

// function isPalindrome(x) {
//     if (x < 0 || (x != 0 && x % 10 == 0)) {
//         return false;
//     }

//     let reversed = 0;
//     while (x > reversed) {
//         reversed = reversed * 10 + x % 10;
//         x /= 10;
//     }
//     return (x == reversed) || (x == reversed / 10);
// }