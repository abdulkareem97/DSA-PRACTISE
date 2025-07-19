// Max Circular Subarray Sum

function circularSubarraySum(arr) {
    // code here
    let maxSum = arr[0]
    for(let i=0;i<arr.length;i++){
        let sum = 0
        let j=0
        while(j<arr.length){
            let k = (i+1+j)%arr.length
            sum+=arr[k]
            j++
            maxSum = Math.max(sum,maxSum)
        }
    }
    return maxSum
}
function circularSubarraySum1(arr) {
    // code here
    let maxSum = arr[0]
    let maxSuffix = new Array(arr.length+1).fill(0)
    let suffixSum = 0
    // maxSuffix[arr.length-1]=suffixSum
    for(let i=arr.length-1;i>=0;i--){
        suffixSum = arr[i]
        maxSuffix[i] = Math.max(suffixSum,maxSuffix[i+1])
    }
    let circularSum = arr[0]
    let normalSum = arr[0]
    let curSum = 0
    let prefixSum = 0
    for(let i=0;i<arr.length;i++){
        curSum = Math.max(arr[i],arr[i]+curSum)
        normalSum = Math.max(normalSum,curSum)

        prefixSum+=arr[i]
        circularSum = Math.max(circularSum,prefixSum+maxSuffix[i+1])


    }
    return Math.max(circularSum,normalSum)
}

function circularSubarraySum2(arr) {
    let curMaxSum = 0,maxSum=0
    let curMinSum = 0,minSum=0
    let totalSum = 0
    for(let i=0;i<arr.length;i++){
        curMaxSum = Math.max(arr[i]+curMaxSum,arr[i])
        maxSum = Math.max(maxSum,curMaxSum)

        curMinSum = Math.min(arr[i]+curMinSum,arr[i])
        minSum = Math.min(curMinSum,minSum)

        totalSum += arr[i]
    }
    let circularSum = totalSum - minSum
    return Math.max(circularSum,maxSum)

}

let arr = [8, -8, 9, -9, 10, -11, 12]
// arr = [-1,-2,2,3,4,-1,-2]
console.log(circularSubarraySum(arr))
console.log(circularSubarraySum1(arr))
console.log(circularSubarraySum2(arr))