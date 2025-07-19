// 4 pillars of oops


// Encapsulation , inheritance , polymorphism , abstraction
#include <iostream>
using namespace std;



// Operator overloading

class Node {
    public:
    int data;
    Node* next=nullptr;
    Node(int data){
        this->data = data;
    }

    int operator+ (int val){
        this->data +=val;
        return val;
    }



};




void printNode(Node *head){
    while (head)
    {
        cout<<" "<<head->data;
        head = head->next;
        /* code */
    }
    cout<<endl;

    
}

int main() {

    Node *head = new Node(10);

    Node *temp = head;


    // temp+head;
    (*temp)+4;

 

    printNode(head);

    
    return 0;
}
