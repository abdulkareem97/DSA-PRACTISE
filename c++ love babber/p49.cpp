// Linked List Problems in leetcode

#include <iostream>
using namespace std;



class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    // Write your code here.
    int cnt0=0,cnt1=0,cnt2=0;
    while(head){
        if(head->data==0) cnt0++;
        else if(head->data==1) cnt1++;
        else cnt2++;
        head=head->next;
    }
    Node *temp = nullptr,*ans = nullptr;
      while(cnt2){
        temp = new Node(2,temp);
        cnt2--;
    }
   

    while(cnt1){
        temp = new Node(1,temp);
       cnt1--;
    }
        while(cnt0){
        temp = new Node(0,temp);
      
        cnt0--;
    }
  
    return temp;
}

int main() {
    
    return 0;
}
