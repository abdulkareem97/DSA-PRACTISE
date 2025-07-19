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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    ListNode* s = new ListNode(0);
    ListNode* x = s;
    while(l1 || l2){
    
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        s->next = new ListNode(sum%10);
        s = s->next;
        sum = sum/10;

        
    }
    if(sum){
         s->next = new ListNode(sum%10);
    }
    return x->next;
}




// add one
  
void recursive(ListNode* &head,ListNode* cur,int &sum){
    if(!cur){
        // head = prev;
        return;
    }
    recursive(head,cur->next,sum);
    // cur->next = prev;
    if(sum){
        sum = (cur->val + 1 )/10;
    cur->val = ((cur->val+1) % 10);
    }
    
    
}


ListNode* addOne(ListNode* head) {
    // Your Code here
    // return head of list after adding one
    int sum = 1;
    recursive(head,head,sum);
    if(sum){
        ListNode* s = new ListNode(1);
        s->next = head;
        head = s;
    }
    return head;
}
int main()
{
    /* code */
    return 0;
}
