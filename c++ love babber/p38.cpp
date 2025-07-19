// 

#include <iostream>
#include<vector>
using namespace std;
   void backtrack(const string arr[], vector<string>& res, string& cur, int ind, const string& digits) {
        if (ind >= digits.size()) {
            res.push_back(cur);
            return;
        }

        string letters = arr[digits[ind] - '2'];  // Get the corresponding letters
        for (char c : letters) {
            cur.push_back(c);      // Choose a letter
            backtrack(arr, res, cur, ind + 1, digits); // Recur for next digit
            cur.pop_back();        // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Edge case: empty input

        string arr[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string cur;
        backtrack(arr, res, cur, 0, digits);
        return res;
    }
int main() {
    string s = "78";
    vector<string> v = letterCombinations(s);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
