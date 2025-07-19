
// 26. Remove Duplicates from Sorted Array



#include <iostream>
#include<vector>
using namespace std;



int removeDuplicates(vector<int>& nums) {
    int j = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i - 1]){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}


int removeDuplicates1(vector<int>& nums) {
    int dub = 0;
    int i=1;
    while(i<nums.size()){
        // nums[dub] = nums[i]
        if(nums[i]==nums[i-1]){
            while(i<nums.size() && nums[i]==nums[i-1]) i++;
            if(i==nums.size()) return dub+1;
        }else{
        }
        dub++;
        nums[dub] = nums[i];
        i++;
    }
    return dub+1;
}


int main() {
    
    return 0;
}
