
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next = nullptr;
  Node(int data, Node *next = nullptr)
  {
    this->data = data;
    this->next = next;
  }
  ~Node()
  {
    if (this->next)
    {
      delete this->next;
      this->next = nullptr;
    }
    cout << " deleting node " << this->data << endl;
  }
};

void printNode(Node *head)
{
  Node *tail = head;
  while (tail)
  {
    cout << " " << tail->data;
    tail = tail->next;
  }
  cout << endl;
}

void createNode(Node *head)
{
  vector<int> arr = {10, 20, 30, 40, 50};
  head->data = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    head->next = new Node(arr[i]);
    head = head->next;
  }
}

void reverse2(Node *&head, Node *&solution)
{
  if (!head || !head->next)
  {
    solution = head;
    return;
  }
  reverse2(head->next, solution);
  head->next->next = head;
  head->next = nullptr;
}

int main()
{
  Node *head = new Node(5);
  createNode(head);
  printNode(head);
  delete head;
  // Node *solution = nullptr;
  // reverse2(head,solution);
  // printNode(solution);
  return 0;
}
