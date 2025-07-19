// // 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

var longestCommonPrefix = function(strs) {
    let t = strs[0]
    for(let i=1;i<strs.length;i++){
        let k = 0 , s = ''
        while(k<strs[i].length && strs[i][k]==t[k]){
                s+=t[k]
                k++
        }
        t = s
    }
    return t
    
};
// string longestCommonPrefix(vector<string>& v) {
//     string ans="";
//     sort(v.begin(),v.end());
//     int n=v.size();
//     string first=v[0],last=v[n-1];
//     for(int i=0;i<min(first.size(),last.size());i++){
//         if(first[i]!=last[i]){
//             return ans;
//         }
//         ans+=first[i];
//     }
//     return ans;
// }