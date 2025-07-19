// 1752. Check if Array Is Sorted and Rotated


#include <iostream>
#include<vector>
using namespace std;


bool check(vector<int>& nums) {
int count = 0, n = nums.size();
for (int i = 0; i < n; i++) 
    if (nums[i] > nums[(i+1)%n] && ++count > 1) return false;
return true;
}

bool check(vector<int>& nums) {
    int pivot = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
            pivot = i;
            break;
        }
    }
    if(!pivot) return true;
    vector<int> b(nums.size());
    b[0] = nums[pivot%nums.size()];
    for(int i=1;i<nums.size();i++){
        b[i] = nums[(i+pivot)%nums.size()];
        if(b[i]<b[i-1]) return false;
    }
    return true;
    
}


int main() {
    
    return 0;
}
