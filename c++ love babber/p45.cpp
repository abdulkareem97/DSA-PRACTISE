// Linked list problems   in leetcode

#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// using recursive
void reverse(ListNode *&head, ListNode *cur, ListNode *prev)
{
    if (!cur)
    {
        head = prev;
        return;
    }

    // ListNode* p = cur;
    reverse(head, cur->next, cur);
    // cout<<" "<<cur->val;
    cur->next = prev;
}

ListNode* reverse2(ListNode *&head){
    if(!head && !head->next){
        return head;
    }
    reverse2(head->next);
    head->next->next = head;
    head->next = nullptr;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *p = head;

    while (p && p->next)
    {
        p = p->next;
    }
    ListNode *cur = head, *prev = nullptr, *next = head;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return p;
}

// Middle of linked list
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{

    return 0;
}
