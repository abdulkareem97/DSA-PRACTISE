#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class SpecialStack {
    int *arr;
    int *arr2;
    int gtop;
    int mini;

    public:
    SpecialStack(){
        arr = new int[1000];
        arr2 = new int[1000];
        gtop = -1;
        mini = INT_MAX;

    }
        
    void push(int data) {
        // Implement the push() function.
        gtop++;
        
        arr[gtop] = data;
        mini = min(mini,data);
        arr2[gtop] = mini;
    }

    void pop() {
        // Implement the pop() function.
        if(gtop==-1) return;
        gtop--;
        if(gtop==-1) mini = INT_MAX;
        else mini = arr2[gtop];
        
    }

    int top() {
        // Implement the top() function.
        if(gtop==-1) return -1;
        return arr[gtop];
    }

    int getMin() {
        // Implement the getMin() function.
                if(gtop==-1) return -1;
        return arr2[gtop];
    }  
};


// using no extra space
class SpecialStack2 {
    stack<int> st;
    int mini;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        if(st.empty()){
            st.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                st.push(2*data - mini);
                mini = data;
            }
            else{
                st.push(data);
            }
        }
    }

    int pop() {
        if(st.empty()){
            return -1;
        }
        int curr = st.top();
        st.pop();
        if(curr<=mini){
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
        else{
            return curr;
        }
    }

    int top() {
        if(st.empty()){
            return -1;
        }
        int curr = st.top();
            
            if(curr < mini){
                return  mini;
            }
            else{
                return curr;
            }
        
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if(st.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }  
};


int main() {
    
    return 0;
}
