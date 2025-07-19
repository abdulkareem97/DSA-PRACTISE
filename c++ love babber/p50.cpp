// Linked List Problems in leetcode

#include <iostream>
#include <unordered_set>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head->next, *prev = head;
    if (!fast)
        return true;
    int cnt = 0;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        cnt++;
    }
    ListNode *s = slow->next;
    if (!fast)
    {
        slow = prev;
    }
    // ListNode *tail = slow;
    // slow = head;
    slow->next = nullptr;
    prev = nullptr;
    ListNode *next = head, *cur = head;
    while (cur)
    {
        // cout<<" "<<cur->val;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    while (slow && slow->val == s->val)
    {
        slow = slow->next;
        s = s->next;
    }
    if (slow)
        return false;
    return true;
}

int main()
{
    /* code */
    return 0;
}
