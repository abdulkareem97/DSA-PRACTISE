// 28. Find the Index of the First Occurrence in a String

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.


function longestPrefixSuffix(pat,lps){
    let n = pat.length
    let i = 1,len=0
    while(i<n){
        if(pat[i]==pat[len]){
            lps[i++]=++len
        }else{
            if(len!=0){
                len = lps[len-1]
            }else{
                lps[i++]=0
            }

        }
    }

}
var strStr = function(haystack, needle) {
    let n = haystack.length,m=needle.length
    let lps = Array(m).fill(0)
    longestPrefixSuffix(needle,lps)
    let i=0,j=0
    while(i<n){
        if(haystack[i]==needle[j]){
            i++
            j++
            // console.log(i,j)
            if(j==m){
                return i-m
            }
        }else{
            if(j!=0){
                j=lps[j-1]
            }else{
                i++
            }
        }
    }
        return -1
};