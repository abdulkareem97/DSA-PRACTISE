// 414. Third Maximum Number

// Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

// Example 1:

// Input: nums = [3,2,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2.
// The third distinct maximum is 1.
// Example 2:

// Input: nums = [1,2]
// Output: 2
// Explanation:
// The first distinct maximum is 2.
// The second distinct maximum is 1.
// The third distinct maximum does not exist, so the maximum (2) is returned instead.
// Example 3:

// Input: nums = [2,2,3,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2 (both 2's are counted together since they have the same value).
// The third distinct maximum is 1.

var thirdMax = function(nums) {
    let f=nums[0],s=-Infinity,t=-Infinity
    for(let i=1;i<nums.length;i++){
        if(f<nums[i]){
            if(s!=-Infinity)
             t = s
            s=f
            f=nums[i]
        }else if(s<nums[i] && f>nums[i]){
            if(s!=-Infinity) t = s
            s=nums[i]
        }else if(t<nums[i] && s>nums[i]){
            t = nums[i]
        }
        console.log(f,s,t)
    }
    // 1 2 2 5 3 5
    // f=1 , s=-1
    // f=2 , s=1
    // f=2 , s=1
    // f=5 , s=2
    // f=5, s=3 
    console.log(f,s,t)
    return t==-Infinity ? f : t
};

let thirdMax = function(nums) {
    // Three variables to store maxiumum three numbers till now.
    let firstMax = Number.MIN_SAFE_INTEGER;
    let secondMax = Number.MIN_SAFE_INTEGER;
    let thirdMax = Number.MIN_SAFE_INTEGER;

    for (let index in nums) {
        let num = nums[index];
        
        // This number is already used once, thus we skip it.
        if (firstMax == num || secondMax == num || thirdMax == num) {
            continue;
        }

        // If current number is greater than first maximum,
        // It means that this is the greatest number and first maximum and second max
        // will become the next two greater numbers.
        if (firstMax <= num) {
            [thirdMax, secondMax, firstMax] = [secondMax, firstMax, num];
        }
        // When current number is greater than second maximum,
        // it means that this is the second greatest number.
        else if (secondMax <= num) {
            [thirdMax, secondMax] = [secondMax, num];
        }
        // It is the third greatest number.
        else if (thirdMax <= num) {
            thirdMax = num;
        }
    }

    // If third max was never updated, it means we don't have 3 distinct numbers.
    if (thirdMax == Number.MIN_SAFE_INTEGER) {
        return firstMax;
    }

    return thirdMax;
};
