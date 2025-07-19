// Stack Implementation in c++

#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int size;
    int top;

public:
    stack(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    void push(int value)
    {
        // cout<<" "<<top<<" "<<size;
        if (top + 1 >= size)
        {
            cout << "Stack Is Full";
            return;
        }
        this->top++;
        this->arr[this->top] = value;
    }
    int pop()
    {
        if (this->top == -1)
        {
            cout << "Stack is Empty";
            return -1;
        }
        return this->arr[this->top--];
    }
    int peek()
    {
        if (this->top == -1)
        {
            cout << "Stack is Empty";
            return -1;
        }
        return this->arr[this->top];
    }
    bool empty()
    {
        return this->top == -1;
    }

    void print()
    {
        // cout<<endl;
        for (int i = 0; i <= this->top; i++)
        {
            cout << " " << this->arr[i];
        }
        cout << endl;
    }
};


// Two Stack implementation
class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        arr = new int[s];
        top1 = -1;
        top2 = s;
        size = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (top1 + 1 == top2)
            return;
        arr[++top1] = num;
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (top1 + 1 == top2)
            return;
        arr[--top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (top1 == -1)
            return -1;
        return arr[top1--];
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (top2 == size)
            return -1;
        return arr[top2++];
    }
};

int main()
{
    stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.push(50);
    // s.print();
    s.pop();
    s.pop();
    s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.peek();
    s.pop();
    cout << s.empty();
    return 0;
}
