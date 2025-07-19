function misingNumber(arr){
    arr.sort((a,b)=>a-b)
    let a = arr.filter((ele)=>ele>0)
    let ans = a[0]
    // console.log(a)
    for (let i = 0; i < a.length-1; i++) {
        // const element = x[i];
        // console.log('here');
        
        if(a[i]==a[i+1] || a[i]+1==a[i+1]){

        }else{
            // console.log(a[i])
                ans = a[i]+1
                break
        }

        
    }
    return ans
}

function misingNumber2(arr){
    let missing = new Array(arr.length).fill(false)
    for (let i = 0; i < arr.length; i++) {
        if(arr[i]>0 && arr[i]<arr.length){
            missing[arr[i]]=true
        }
        
    }
    for (let i = 1; i < arr.length; i++) {
        if(!missing[i]){
            return i
        }
        
    }
    return arr.length+1
}

let a = [-1,3,1,0]
a=[2, -3, 4, 1, 1, 7]
const res=misingNumber(a)
a=[2, -3, 4, 1, 1, 7]
a= [1,2,3,4]
const res2=misingNumber2(a)
console.log(res,res2);
