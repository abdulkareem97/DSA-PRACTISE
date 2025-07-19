// STL Library

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
// #include<String>

using namespace std;

int main()
{

    // Array

    array<int, 4> a = {10, 20, 30, 40};
    // cout<<" size "<<a.size();
    // for(int ele:a){
    //     cout<<" "<<ele;
    // }
    // cout<<a.at(2)<<" "<<a[2];
    // cout<<" Is Empty "<<a.empty();
    // cout<<" First Element "<<a.front();
    // cout<<" Last Element "<<a.back();
    // cout<<a;  // Error
    // cout<<*(a.begin()+1);

    // Vector

    vector<int> v;
    // cout<<" Capacity "<<v.capacity()<<endl;
    v.push_back(3);
    // cout<<" Capacity "<<v.capacity()<<endl;
    v.push_back(4);
    // cout<<" Capacity "<<v.capacity()<<endl;
    v.push_back(5);
    // cout<<" Capacity "<<v.capacity()<<" size "<<v.size()<<endl;
    // for(auto ele:v){
    //     cout<<" "<<ele;
    // }
    // v.pop_back();
    //  for(auto ele:v){
    //     cout<<" "<<ele;
    // }
    // v.pop_back();
    // v.erase(v.begin()+1);
    //      for(auto ele:v){
    //     cout<<" "<<ele;
    // }
    // cout<<" Capacity "<<v.capacity()<<" size "<<v.size()<<endl;
    // vector<int> v1(5,1);
    vector<int> v1 = {1, 2, 3};
    //      for(auto ele:v1){
    //     cout<<" "<<ele;
    // }


    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    // for(auto ele:d){
    //     cout<<" "<<ele;
    // }
    d.pop_front();
    // d.pop_back();
    // for (auto ele : d)
    // {
    //     cout << " " << ele;
    // }
    d.erase(d.begin(),d.begin()+1);
    //     for (auto ele : d)
    // {
    //     cout << " " << ele;
    // }
    // cout<<" completed "<<endl;


    // List

    list<int> l;
    l.push_back(1);
    l.push_front(0);

    l.pop_back();
    l.push_back(20);
    // for(auto ele:l){
    //     cout<<" "<<ele;
    // }
    // cout<<" element at "<<l[1];  gives error


    // Stack

    stack<int> s;
    s.push(1);
    s.push(2);
    // cout<<" Top Element is "<<s.top();
    s.pop();
    s.empty();
    s.top();

    
    // for(auto ele:s){   gives error
    //     cout<<" "<<ele;
    // }
    // cout<<" element at "<<s[1]; gives error


    // Queue

    queue<int> q;
    q.push(1);
    q.push(2);

    // cout<<" First Element "<<q.front();
    q.pop();
    
    // cout<<" First Element "<<q.front();


    // Priority Queue

    priority_queue<int> pq;   // Max Heap
    pq.push(10);
    pq.push(4);
    pq.push(7);
    pq.push(20);

    // cout<<" First Elment is "<<pq.top();

    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(4);
    minHeap.push(7);
    minHeap.push(20);

    // cout<<" First Element is "<<minHeap.top(); 
    

    // Set

    set<int> st;

    st.insert(5);
    st.insert(5);
    st.insert(5);

    // cout<<" size "<<st.size();
    // for(auto e:st){
    //     cout<<" "<<e;
    // }
    st.insert(10);
    set<int>::iterator it= st.begin();
    it++;
    st.erase(it);
    // cout<<" size "<<st.size()<<endl;
    //    for(auto e:st){
    //     cout<<" "<<e;
    // }

    st.insert(10);
    st.insert(20);
    // cout<<" Element 5 is present "<<st.count(5);  // return 0 or 1 based on element is present or not
    // cout<<" Element 5 at "<<*st.find(10);

    // Map

    map<int,int> m;
    m[1] = 10;
    m[2] = 20;
    m[3] = 5;
    m[0] = 30;
    m.insert({-1,50});
    // for(auto i:m){
    //     cout<<" "<<i.second;
    // }
    // cout<<" Finding 3 key "<<m.count(10);

    //  cout<<" Finding 0 key "<<m.count(0);
    m.erase(0);
    //  cout<<" Finding 0 key "<<m.count(0);

    // unorder Map

    unordered_map<int,int> um;
        um[1] = 10;
    um[2] = 20;
    um[3] = 5;
    um[0] = 30;
    um.insert({-1,50});
    um[0] = 99;
    // for(auto i:um){
    //     cout<<" "<<i.second;
    // }


    vector<int> vi = {10,20,30,40};
    // cout<<" Element found "<<binary_search(vi.begin(),vi.end(),0);
    // cout<<" Element Found At "<<lower_bound(vi.begin(),vi.end(),20)-v.begin();

    int a1 = 4;
    int b1 = 5;
    // cout<<" Max Value "<<max(a1,b1);
    // cout<<" Min Value "<<min(a1,b1);

    swap(a1,b1);
    // cout<<" a "<<a1<<" b "<<b1;

    string str = "abcd";
    // reverse(str.begin(),str.end());
    rotate(str.begin(),str.begin()+1,str.end());
    cout<<str;

    vector<int>  vs = {10,40,20,30};
    sort(vs.begin(),vs.end());
    for(auto ele:vs){
        cout<<" "<<ele;
    }

    return 0;
}
