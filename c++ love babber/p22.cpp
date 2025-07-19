// Character Array and String

#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

// Length of a string
int length(string s)
{
    int i = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    return i;
}

// 344. Reverse String
void reverseString(string &s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        swap(s[s.size() - 1 - i], s[i]);
    }
}

// check palindrome

char covertToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    return c;
}
bool isValidChar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}
bool isPalindrome(string s)
{
    int n = s.length();
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (!isValidChar(s[low]))
        {
            low++;
            continue;
        }
        if (!isValidChar(s[high]))
        {
            high--;
            continue;
        }
        if (covertToLower(s[low]) != covertToLower(s[high]))
            return false;
        low++;
        high--;
    }
    return true;
}
// noo!n

//  Reverse Words in a String II
string reverseOrderWords(string str)
{
    // Write your code here
    string s;
    string ans;
    str += ' ';

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
            s += str[i];
        else
        {
            ans = s + " " + ans;
            s = "";
        }
    }
    return ans;
}

// Max
char getMaxOccuringChar(string &s)
{
    // Your code here
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {

        m[s[i]]++;
    }
    char ans = ' ';
    int num = -1;
    for (auto i : m)
    {
        if (i.second >= num)
        {
            if (i.second == num && i.first > ans)
            {
                continue;
            }
            num = i.second;
            ans = i.first;
        }
    }
    return ans;
}

// 1910. Remove All Occurrences of a Substring
string removeOccurrences(string s, string part)
{
    int m = part.size();
    int i = s.find(part);
    while (i != string::npos)
    {
        s.erase(s.begin() + i, s.begin() + i + m);
        i = s.find(part);
    }
    return s;
}

// 443. String Compression

int compress(vector<char> &chars)
{
    int occ = 1;
    int ans = 0;
    for (int i = 1; i < chars.size() + 1; i++)
    {
        if (i < chars.size() && chars[i - 1] == chars[i])
        {
            occ++;
        }
        else
        {
            chars[ans] = chars[i - 1];
            ans++;
            if (occ > 1)
            {

                int temp = occ;
                int x = 1;
                while (temp)
                {
                    // digit++;
                    x = x * 10;
                    temp = temp / 10;
                }

                x = x / 10;

                // cout<<" "<<occ<<" "<<x;
                while (x)
                {
                    // cout<<" "<<occ/x;
                    chars[ans] = '0' + occ / x;
                    ans++;
                    occ = occ % x;
                    x = x / 10;
                }
                occ = 1;
            }
        }
    }
    return ans;
}

// 567. Permutation in String
bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> m1, m2;
    int l1 = s1.size(), l2 = s2.size();
    if (l1 > l2)
        return false;
    for (int i = 0; i < l1; i++)
    {
        m1[s1[i]]++;
        m2[s2[i]]++;
    }
    int k = l1 - 1;
    for (int i = 0; i < l2 - l1 + 1; i++)
    {
        if (m1 == m2)
            return true;
        m2[s2[i]]--;
        if (m2[s2[i]] == 0)
        {
            m2.erase(s2[i]);
        }
        m2[s2[i + l1]]++;
    }
    return false;
}

// 1047. Remove All Adjacent Duplicates In String
string removeDuplicates(string s)
{
    int i = 1;
    while (i < s.size())
    {
        if (s[i] == s[i - 1])
        {
            s.erase(i - 1, 2);
            i--;
            i = i < 1 ? 1 : i;
        }
        else
        {
            i++;
        }
    }
    return s;
}

int main()
{
    string s = "heelo";

    // cout<<length(s);
    // reverseString(s);
    // cout<<s;

    s = "no!@On";
    // s = "noo!n";
    cout << boolalpha;
    // cout<<isPalindrome(s);
    string str = "when all else fails reboot";
    // cout<<reverseOrderWords(str);

    s = "aabcadbbbb";
    // cout << "Max Occurance Char " << getMaxOccuringChar(s);
    // cout<<s.find("abcd");

    s = "123456";
    // s.erase(s.begin(), s.begin() + 1);
    s.erase(3, 1);
    // cout << s;
    string part;
    s = "daabcbaabcbc", part = "abc";
    // cout<<removeOccurrences(s,part);

    // s.erase()

    string s1, s2;
    s1 = "ab", s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);

    return 0;
}

/*


To effectively handle strings in C++ for competitive programming (CP), it’s crucial to master the most commonly used methods, functions, and algorithms. Here's a comprehensive guide to strings in C++ for CP:

1. Basics of Strings
String Initialization:


string s = "hello";
string s2("world");
string s3(5, 'a');  // "aaaaa"
Access Characters:


cout << s[0];      // 'h'
cout << s.at(1);   // 'e'
Concatenation:


string s = "hello";
s += " world";  // "hello world"
2. Common String Functions
Size and Capacity
Length/Size:


string s = "hello";
cout << s.size();   // 5
cout << s.length(); // 5
Resize:


s.resize(3);  // "hel"
Manipulation
Append:


string s = "hello";
s.append(" world");  // "hello world"
Insert:


string s = "hello";
s.insert(2, "y");  // "heylo"
Erase:


string s = "hello";
s.erase(1, 2);  // "hlo" (erase 2 chars from index 1)
Replace:


string s = "hello";
s.replace(1, 2, "ey");  // "heylo"
Substrings
Find Substring:


string s = "hello world";
cout << s.find("world");  // 6
cout << s.find("oops");   // string::npos (not found)
Substring Extraction:


string s = "hello world";
cout << s.substr(6, 5);  // "world"
Reverse and Sort
Reverse:


string s = "hello";
reverse(s.begin(), s.end());  // "olleh"
Sort:


string s = "bacd";
sort(s.begin(), s.end());  // "abcd"
Comparison
Equality:


string s1 = "abc", s2 = "abc";
if (s1 == s2) cout << "Equal";
Lexicographical Comparison:


string s1 = "abc", s2 = "abd";
if (s1 < s2) cout << "s1 is smaller";
3. Advanced String Functions
Search
RFind (Reverse Find):


string s = "hello world";
cout << s.rfind("l");  // 9
Count Occurrences:


string s = "ababa";
cout << count(s.begin(), s.end(), 'a');  // 3
Tokenization
Using stringstream:

string s = "abc def ghi";
stringstream ss(s);
string word;
while (ss >> word) {
    cout << word << endl;  // Prints "abc", "def", "ghi"
}
Converting Between String and Numbers
String to Integer:


string s = "123";
int num = stoi(s);  // 123
Integer to String:


int num = 123;
string s = to_string(num);  // "123"
Float to String:


float f = 3.14;
string s = to_string(f);  // "3.140000"
Lowercase and Uppercase Conversion
Manual Conversion:

string s = "Hello";
for (char& c : s) c = tolower(c);  // "hello"
for (char& c : s) c = toupper(c);  // "HELLO"
4. Common Algorithms with Strings
Palindrome Check

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}
Longest Prefix-Suffix (KMP Algorithm)

vector<int> computeLPSArray(string s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}
5. Time Complexity for String Operations
Length:
𝑂
(
1
)
O(1)
Access (indexing):
𝑂
(
1
)
O(1)
Appending: Amortized
𝑂
(
1
)
O(1)
Erase/Insert:
𝑂
(
𝑛
)
O(n)
Sort/Reverse:
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn)
Find:
𝑂
(
𝑛
)
O(n)
Substr:
𝑂
(
𝑘
)
O(k), where
𝑘
k is the length of the substring.
Master These for CP:
Sorting and reversing strings.
Using stringstream for parsing.
Prefix arrays (like KMP's LPS array).
Palindrome, subsequence, and anagram problems.
Efficient I/O for large strings:

ios::sync_with_stdio(0);
cin.tie(0);
These skills will help you solve almost every string-related problem in competitive programming!

*/