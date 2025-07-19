function nextPermutation(arr){
    let pivot = -1
    const n = arr.length
    for(let i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            pivot=i
            break
        }
    }
    console.log(pivot);
    if(pivot==-1){
        arr.reverse()
        return
    }
    for(let i=n-1;i>pivot;i--){
        if(arr[i]>arr[pivot]){
            [arr[pivot],arr[i]]=[arr[i],arr[pivot]]
            break
        }
    }
    let left = pivot+1
    let right = n-1
    while(left<right){
        [arr[left],arr[right]]=[arr[right],arr[left]]
        left++
        right--
    } 
         

 } 

let arr =   [1,2,3]
nextPermutation(arr)
console.log(arr)
nextPermutation(arr)
console.log(arr)
nextPermutation(arr)
console.log(arr)
nextPermutation(arr)
console.log(arr)