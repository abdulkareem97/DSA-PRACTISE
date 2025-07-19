// 953. Verifying an Alien Dictionary

// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
// Example 3:

// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

var isAlienSorted = function(words, order) {
    let obj = {},k=0
    for(let ch of order){
        obj[ch] = k++
    }
    for(let i=0;i<words.length-1;i++){
        // for(let )
        let x = words[i]
        let y = words[i+1]
        let a=0,b=0
        while(a<x.length){
            if(obj[x[a]]>obj[y[b]]) return false
            if(obj[x[a]]<obj[y[b]]) break
            
            a++
            b++
            if(a<x.length && b>=y.length) return false
        }
    }
    return true
};