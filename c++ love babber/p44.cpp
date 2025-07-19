// Linked List and its types

#include <iostream>
using namespace std;

// single linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// insertion at head
void insertionAtHead(int value, Node *&head)
{
    Node *p = new Node(value);
    p->next = head;
    head = p;
}
void insertionAtTail(int value, Node *&head)
{
    Node *p = new Node(value);
    Node *temp = head;
    if (!temp)
    {
        head = p;
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = p;
}

void insertAtMiddle(int value, int pos, Node *&head)
{
    Node *p = new Node(value);
    Node *temp = head;
    if (pos == 1)
    {
        // cout<<"here";
        p->next = head;
        head = p;
        return;
    }
    int i = 2;
    while (i < pos && temp->next)
    {
        temp = temp->next;
        i++;
    }
    if (i != pos)
    {
        cout << " Invalid Position " << endl;
        return;
    }
    // cout<< temp->data;
    p->next = temp->next;
    temp->next = p;
}

// delete node
void deleteNodeByPos(int pos, Node *&head)
{
    if (pos == 1)
    {
        head = head->next;
        return;
    }
    int i = 2;
    Node *temp = head;
    while (i < pos && temp->next)
    {
        temp = temp->next;
        i++;
    }
    if(! temp->next){
        cout<<" Invalid Position to delete "<<endl;
        return;
    }
    temp->next = temp->next->next;
}
void deleteNodeByValue(int value, Node *&head)
{
    if (head->data == value)
    {
        head = head->next;
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data != value)
    {
        temp = temp->next;
    }
    if(! temp->next){
        cout<<" Invalid Value to delete "<<endl;
        return;
    }
    temp->next = temp->next->next;
}

// Display Nodes
void display(Node *head)
{
    while (head)
    {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}




int main()
{
    Node *p = new Node(5);
    // display(p);
    insertionAtHead(4, p);
    // display(p);
    // Node* p = nullptr;
    insertionAtTail(6, p);
    insertionAtTail(8, p);
    display(p);
    // insertAtMiddle(7,4,p);
    // insertAtMiddle(0,2,p);
    insertAtMiddle(-1, 1, p);
    insertAtMiddle(9, 6, p);
    insertAtMiddle(10, 8, p);

    deleteNodeByPos(1,p);
    deleteNodeByPos(5,p);
    deleteNodeByPos(5,p);
    display(p);
    deleteNodeByValue(8,p);
    deleteNodeByValue(4,p);
    deleteNodeByValue(10,p);
    display(p);

    cout<< " finish "<<endl;

    return 0;
}
