// questions on queue

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// Queue Reversal
queue<int> reverseQueue(queue<int> &q)
{
    // code here.
    vector<int> v(q.size());
    int i = q.size() - 1;
    while (!q.empty())
    {
        v[i] = q.front();
        i--;
        q.pop();
    }
    queue<int> ans;
    for (auto ele : v)
    {
        ans.push(ele);
    }

    return ans;
}

// First negative in every window of size k
vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    // write code here
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push(arr[i]);
    }
    for (int i = 0; i + k <= arr.size(); i++)
    {
        if (q.empty())
            ans.push_back(0);
        else
        {
            ans.push_back(q.front());
            if (arr[i] == q.front())
                q.pop();
        }
        if (arr[i + k] < 0)
            q.push(arr[i + k]);
    }
    return ans;
}

// Reverse First K elements of Queue
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    vector<int> v(q.size(), 0);
    int i = k - 1;
    while (i > -1)
    {
        v[i] = q.front();
        i--;
        q.pop();
    }
    i = k;
    while (!q.empty())
    {
        v[i] = q.front();
        i++;
        q.pop();
    }
    for (auto ele : v)
    {
        q.push(ele);
    }
    return q;
}

// Input : s = "aabc" 
// Output : "a#bb"
//  Explanation : For every ith character we will consider
//  the string from index 0 till index i first non repeating character is as follow - "a" - first
//   non - repeating character is 'a' "aa" - no non - repeating character so '#' "aab" - first non - repeating
//    character is 'b' "aabc" - there are two non repeating characters 'b' and 'c', first non - repeating character
//    is 'b' because 'b' comes before 'c' in the stream.
string FirstNonRepeating(string &s)
{
    // Code here
    string ans = "";
    queue<char> q;
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
        q.push(s[i]);
        while (!q.empty())
        {
            if (m[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans += q.front();
                break;
            }
        }
        if (q.empty())
            ans += '#';
    }
    return ans;
}


// A C++ class to represent k queues 
// in a single array of size n
class kQueues
{   
    // Array of size n to store actual 
    // content to be stored in queue
    int *arr;
 
    // Array of size k to store indexes 
    // of front elements of the queue  
    int *front;   
 
    // Array of size k to store indexes 
    // of rear elements of queue
    int *rear; 
 
    // Array of size n to store next 
    // entry in all queues            
    int *next;  
    int n, k;
 
    int free; // To store the beginning index of the free list
 
public:
    //constructor to create k queue 
    // in an array of size n
    kQueues(int k, int n);
 
    // A utility function to check if 
    // there is space available
    bool isFull()   {  return (free == -1);  }
 
    // To enqueue an item in queue number 
    // 'qn' where qn is from 0 to k-1
    void enqueue(int item, int qn);
 
    // To dequeue an from queue number 
    // 'qn' where qn is from 0 to k-1
    int dequeue(int qn);
 
    // To check whether queue number
    // 'qn' is empty or not
    bool isEmpty(int qn)  {  return (front[qn] == -1); }
};
 
// Constructor to create k queues 
// in an array of size n
kQueues::kQueues(int k1, int n1)
{
    // Initialize n and k, and allocate
    // memory for all arrays
    k = k1, n = n1;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    next = new int[n];
 
    // Initialize all queues as empty
    for (int i = 0; i < k; i++)
        front[i] = -1;
 
    // Initialize all spaces as free
    free = 0;
    for (int i=0; i<n-1; i++)
        next[i] = i+1;
    next[n-1] = -1;  // -1 is used to indicate end of free list
}
 
// To enqueue an item in queue number 
// 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int qn)
{
    // Overflow check
    if (isFull())
    {
        cout << "\nQueue Overflow\n";
        return;
    }
 
    int i = free;      // Store index of first free slot
 
    // Update index of free slot to index of next slot in free list
    free = next[i];
 
    if (isEmpty(qn))
        front[qn] = i;
    else
        next[rear[qn]] = i;
 
    next[i] = -1;
 
    // Update next of rear and then rear for queue number 'qn'
    rear[qn] = i;
 
    // Put the item in array
    arr[i] = item;
}
 
// To dequeue an from queue number 'qn' where qn is from 0 to k-1
int kQueues::dequeue(int qn)
{
    // Underflow checkSAS
    if (isEmpty(qn))
    {
         cout << "\nQueue Underflow\n";
         return INT_MAX;
    }
 
    // Find index of front item in queue number 'qn'
    int i = front[qn];
   
    // Change top to store next of previous top
    front[qn] = next[i]; 
 
    // Attach the previous front to the
    // beginning of free list
    next[i] = free;
    free = i;
 
    // Return the previous front item
    return arr[i];
}


// Sum of minimum and maximum elements of all subarrays of size k
int SumOfKsubArray(vector<int> arr,int k){
    int ans = 0;
    int n = arr.size();
    deque<int> maxi;
    deque<int> mini;
    int i=0;


    
    for(;i<k;i++){

        // if greater element is found remove previos greater elements
        while(!maxi.empty() && maxi.back()<=arr[i]) maxi.pop_back();
        while(!mini.empty() && mini.back()>=arr[i]) mini.pop_back();
        maxi.push_back(arr[i]);
        mini.push_back(arr[i]);
    }

    for(;i<n;i++){
        
        ans += maxi.front() + mini.front();

        // if greater element is first remove greater element
        if(!maxi.empty() && maxi.front()==arr[i-k]) maxi.pop_front();
        if(!mini.empty() && mini.front()==arr[i-k]) mini.pop_front();
        while(!maxi.empty() && maxi.back()<=arr[i]) maxi.pop_back();
        while(!mini.empty() && mini.back()>=arr[i]) mini.pop_back();
        maxi.push_back(arr[i]);
        mini.push_back(arr[i]);

    }
    ans += maxi.front() + mini.front();
    return ans;
    
}

int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2} ;
    int k = 4;
    cout<<SumOfKsubArray(arr,k);

    return 0;
}
