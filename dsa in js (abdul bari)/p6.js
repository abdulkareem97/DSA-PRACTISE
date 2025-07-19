const getMinDiff = (arr,k)=>{
    let n = arr.length
    arr.sort((a,b)=>a-b)
    let min = arr[0]+k
    let max = arr[n-1]-k < 0 ? arr[n-1]+k : arr[n-1]-k
    // console.log(min,max);
    
    let res = max-min
    for (let i = 0; i < arr.length; i++) {
        let ele = arr
        

        
    }
    // console.log(res);
    return res
    
}

let k=2,arr=[1,5,8,10]
arr=[3, 9, 12, 16, 20],k=3
const res = getMinDiff(arr,k)
console.log(res);
