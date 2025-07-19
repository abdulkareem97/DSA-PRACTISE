// 138. Copy List with Random Pointer
#include <iostream>
#include<unordered_map>
using namespace std;


// refer these for doing without map
// https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/#naive-approach-clone-a-linked-list-with-next-and-random-pointer-using-hashing-o2n-time-and-o2n-space

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, Node *> m;
    Node *s = new Node(0);
    Node *st = s;
    while (temp)
    {
        s->next = new Node(temp->val);
        temp = temp->next;
        s = s->next;
    }
    temp = head;
    s = st->next;
    while (temp)
    {
        m[temp] = s;
        temp = temp->next;
        s = s->next;
    }
    temp = head;
    s = st->next;
    while (s)
    {
        s->random = m[temp->random];
        temp = temp->next;
        s = s->next;
    }

    return st->next;
}

int main()
{

    return 0;
}
