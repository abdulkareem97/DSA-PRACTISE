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


// in sorted linked list
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    while (temp && temp->next)
    {
        if (temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
            // break;
        }
        else
            temp = temp->next;
    }
    return head;
}


// in unsorted linked list
ListNode *removeDuplicates(ListNode *head)
{
    // Write your code here
    unordered_set<int> s;
    ListNode *temp = head,*prev = head;
    while(temp){

        if(s.find(temp->val)!=s.end()){
            prev->next = temp->next;

        }else{
            prev = temp;
            s.insert(temp->val);
        }

            temp = temp->next;
    }
    return head;
}
int main()
{

    return 0;
}
