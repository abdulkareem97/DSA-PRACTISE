#include <iostream>
#include<queue>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int rear;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[6000];
        qfront = -1;
        rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return rear==qfront;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        rear++;
        arr[rear] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==rear) return -1;
        qfront++;
        return arr[qfront];
    }

    int front() {
        // Implement the front() function
        if(rear==qfront) return -1;
        return arr[qfront+1];
    }
};


class CircularQueue{
    int *arr;
    int front;
    int rear;
    int count;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        arr = new int[n];
        front = 0;
        rear = 0;
        count =0;
        size = n;

    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(count==size) return false;
        arr[rear] = value;
        rear = (rear+1)%size;
        count++;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(count==0) return -1;
        int data = arr[front];
        front = (front+1)%size;
        count--;
        return data;
    }
};


class CircularQueue1{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue1(int n){
        // Write your code here.
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;

    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        // cout<<" r "<<rear<<" f "<<front<<endl;
        if(isFull()) return false;
        if(front==-1){
            front=rear=0;
            arr[rear] = value;
        }else{
            rear = (rear+1)%size;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(isEmpty()) return -1;
        int data = arr[front];
        if(front==rear) front=rear=-1;
        else 
        front = (front+1)%size;
        return data;
    }

    bool isFull(){
        if((rear+1)%size == front) return true;
        return false;
    }
    bool isEmpty(){
        return front==-1;
    }
};


class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()) return false;
        if(front==-1){
            front = 0;
            rear = 0;
        }else{
            front = front-1>=0 ? front-1 : size-1 ;
        }
            arr[front] = x;
         return true;   

    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()) return false;
        if(front==-1){
            front = 0;
            rear = 0;
        }else{
            rear = (rear+1)%size;
        }
            arr[rear] = x;
         return true;   
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        int data = arr[front];
        if(front==rear) front=rear=-1;
        else front = (front+1)%size;
        return data;

    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()) return -1;
        int data = arr[rear];
        if(front==rear) front=rear=-1;
        else rear = rear==0 ? size-1 : rear-1;
        return data;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
         if(isEmpty()) return -1;
         return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()) return -1;
         return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return front==-1;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        return ( (rear+1)%size == front );
    }
};
int main() {

    queue<int> q;
    q.push(5);
    
    q.push(10);

    q.push(15);

    q.pop();

    cout<<" is empty "<<q.empty()<<endl;
    cout<<" size "<<q.size()<<endl;

    cout<<" front "<<q.front()<<" back "<<q.back()<<endl;

    cout<<" DEQUE "<<endl;
    deque<int> dq;
    dq.push_back(4);
    dq.push_front(5);
    cout<<" front "<<dq.front()<<" back "<<dq.back()<<endl;
    dq.pop_back();
    cout<<" front "<<dq.front()<<" back "<<dq.back()<<endl;
    return 0;
}
