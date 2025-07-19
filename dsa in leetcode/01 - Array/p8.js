// 169. Majority Element

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

var majorityElement = function(nums) {
    let obj = {},majority = Math.floor(nums.length/2)
    for(let i=0;i<nums.length;i++){
        obj[nums[i]] = (obj[nums[i]] || 0) + 1
        if(obj[nums[i]]>majority){
            return nums[i]
        }
    }
};


// Moore Voting Algorithm

// int majorityElement(vector<int>& nums) {
//     int count = 0;
//     int candidate = 0;
    
//     for (int num : nums) {
//         if (count == 0) {
//             candidate = num;
//         }
        
//         if (num == candidate) {
//             count++;
//         } else {
//             count--;
//         }
//     }
    
//     return candidate;
// }