#include <iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Print all the duplicate characters in a string
void printDublicate(string s){
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }
    for(auto i:m){
        if(i.second>1)
        cout<<" count of "<<i.first<<" is "<<i.second<<endl;
    }
}

// using sorting
void printDublicateS(string s){
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        int count = 1;
        while(i<s.size()-1 && s[i]==s[i+1]){
            count++;
            i++;
        }
        if(count>1)
        cout<<" count of "<<s[i]<<" is "<<count<<endl;
    }
}

int main() {
    string s = "hellohoo";
    printDublicate(s);
    cout<<endl;
    printDublicateS(s);
    return 0;
}
