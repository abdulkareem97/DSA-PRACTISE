// 830. Positions of Large Groups

// In a string s of lowercase letters, these letters form consecutive groups of the same character.

// For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

// A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

// A group is considered large if it has 3 or more characters.

// Return the intervals of every large group sorted in increasing order by start index.

 

// Example 1:

// Input: s = "abbxxxxzzy"
// Output: [[3,6]]
// Explanation: "xxxx" is the only large group with start index 3 and end index 6.
// Example 2:

// Input: s = "abc"
// Output: []
// Explanation: We have groups "a", "b", and "c", none of which are large groups.
// Example 3:

// Input: s = "abcdddeeeeaabbbcd"
// Output: [[3,5],[6,9],[12,14]]
// Explanation: The large groups are "ddd", "eeee", and "bbb".

var largeGroupPositions = function(s) {
    let ans = []
        for(let i=0;i<s.length-1;i++){
            let char = s[i]
            let c = 0,si=i
            i++
            while(i<s.length && char==s[i]){
                i++
            }
            let end = i
            i--
            if(end-si>=3) ans.push([si,end-1])
        }
        return ans
        
};

// var largeGroupPositions = function(s) {
//     let returnVal = [];
//     let start = -1, end = -1;
//     let prevChar = '', currChar = '';

//     for(let i=0; i<s.length; i++) {
//         currChar = s.charAt(i);
//         if(prevChar === currChar) {
//             end += 1;
//             if(i === s.length - 1 && end - start >= 2) returnVal.push([start, end]);
//         }
//         else {
//             if(end - start >= 2) returnVal.push([start, end]);
//             prevChar = currChar;
//             start = i;
//             end = i;
//         }

//     }

//     return returnVal;
// };