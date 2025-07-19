// MergeSort Linked List

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *merge(node *first, node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    node *temp = new node(0);
    node *ans = temp;
    while (first && second)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            temp = temp->next;
            first = first->next;
        }
        else
        {
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
    }
    while (first)
    {
        temp->next = first;
        temp = temp->next;
        first = first->next;
    }
    while (second)
    {
        temp->next = second;
        temp = temp->next;
        second = second->next;
    }
    return ans->next;
}

node *getHalf(node *head)
{
    node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *mergeSort(node *head)
{
    // Write your code here.
    if (head && head->next)
    {
        node *mid = getHalf(head);
        node *sec = mid->next;
        mid->next = nullptr;
        // cout<<" "<<head->data<<"  "<<sec->data<<endl;
        head = mergeSort(head);
        sec = mergeSort(sec);
        return merge(head, sec);
    }
    return head;
}

int main()
{

    return 0;
}
