// Doubly linked list

#include <iostream>
using namespace std;

// Doubly Linked List
class Node{
    public:
    int data;
    Node *prev,*next;
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};





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

//  count Node 
// Display Nodes
int count(Node *head)
{
    int c =0;
    while (head)
    {
        c++;
        // cout << " " << head->data;
        head = head->next;
    }
    // cout << endl;
    return c;
}

// insertion at head
void insertionAtHead(Node *&head,int value)
{
    Node *p = new Node(value);
    p->next = head;
    head->prev = p;
    head = p;
}




int main() {
    Node *p = new Node(5);
    // display(p);
    // cout<< count(p);

    insertionAtHead(p,4);
    display(p);

    return 0;
}
