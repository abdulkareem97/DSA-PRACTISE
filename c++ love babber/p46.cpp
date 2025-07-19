// Linked List Problems in leetcode

#include <iostream>
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

ListNode *reverse(ListNode *&head, int k, ListNode *prev)
{

    if (!head)
    {
        return head;
    }

    ListNode *tail = head;
    int i = 1;
    while (tail->next && i < k)
    {
        tail = tail->next;
        i++;
    }
    if (i != k)
    {
        return head;
    }
    cout << tail->val << " ";
    ListNode *next = head, *cur = head;
    i = 0;
    while (cur && i < k)
    {
        next = cur->next;
        cur->next = prev;
        // cout<< cur->val << " ";
        prev = cur;
        cur = next;
        i++;
    }
    head->next = reverse(cur, k, prev);
    return tail;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    return reverse(head, k, nullptr);
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}
