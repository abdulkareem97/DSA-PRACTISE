// // 1941. Check if All Characters Have Equal Number of Occurrences
// Given a string s, return true if s is a good string, or false otherwise.

// A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

 

// Example 1:

// Input: s = "abacbc"
// Output: true
// Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
// Example 2:

// Input: s = "aaabb"
// Output: false
// Explanation: The characters that appear in s are 'a' and 'b'.
// 'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

var areOccurrencesEqual = function(s) {
    let obj = {}
    for(let i=0;i<s.length;i++){
        obj[s[i]] = (obj[s[i]] || 0) + 1
    }
    let num = obj[s[0]]
    for(key in obj){
        if(obj[key]!=num) return false
    }
    return true
};

// def areOccurrencesEqual(self, s: str) -> bool:
// m = set(s)
// print(m)
// h={}
// for char in s:
//     if char in h:
//         h[char]+=1
//     else:
//         h[char]=1
// return len(set(h.values())) == 1