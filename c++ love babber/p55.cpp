// stack interview questions

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// reverse using stack
void reverse(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << ans;
}

// Delete middle element from stack
void solve(stack<int> &st, int c, int s)
{
    if (c == s / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    solve(st, c + 1, s);
    st.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{

    // Write your code here
    int count = 0;
    solve(inputStack, count, N);
}

//  Valid Parentheses

bool isValidParenthesis(string s)
{
    // Write your code here.
    unordered_map<char, char> m;
    stack<char> st;
    m['{'] = '}';
    m['('] = ')';
    m['['] = ']';

    for (char c : s)
    {
        if (c == '{' || c == '(' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || m[st.top()] != c)
                return false;
            st.pop();
        }
    }

    return st.empty();
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    stack<int> st;
    while (!myStack.empty())
    {
        st.push(myStack.top());
        myStack.pop();
    }
    st.push(x);
    while (!st.empty())
    {
        myStack.push(st.top());
        st.pop();
    }

    return myStack;
}

// reverse a stack using recursion
void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int num1 = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(num1);
}

void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    // stack.push(num);
    insertAtBottom(stack, num);
}

void insertAtCorrectPosition(stack<int> &stack, int ele)
{
    if (stack.empty() || stack.top() < ele)
    {
        stack.push(ele);
        return;
    }
    int num = stack.top();
    stack.pop();
    insertAtCorrectPosition(stack, ele);
    stack.push(num);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insertAtCorrectPosition(stack, num);
    // stack.push(num);
}

// 2
// (a+b)
// (a+c*b)+(c))
// Sample Output 1 :
// No
// Yes

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<int> st;
    for (auto c : s)
    {
        if (c == '(')
        {
            st.push(false);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (!st.empty() && !st.top())
            {
                st.pop();
                st.push(true);
            }
            // st.pop();
            // st.push(true);
            // st[st.size()-1] = true;
        }
        else if (c == ')')
        {
            if (!st.top())
                return true;
            st.pop();
        }
    }
    return false;
}

int findMinimumCost(string str)
{
    // Write your code here
    int count = 0;
    stack<char> s;

    if (str.size() % 2 == 1)
        return -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                count++;
                str[i] = '{';
                s.push(str[i]);
            }
            else if (s.top() == '{')
            {
                s.pop();
            }
        }
    }

    return count + s.size() / 2;
}

int main()
{
    reverse("love");
    return 0;
}
