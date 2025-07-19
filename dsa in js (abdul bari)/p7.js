const maxSubArray = (arr)=>{
    let res  = arr[0]
    let ind = [0,0]
    for(let i=0;i<arr.length;i++){
        let sum=0
        for(let j=i;j<arr.length;j++){
            sum+=arr[j]
            // res= Math.max(sum,res)
            if(res<sum){
                ind[0]=i
                ind[1]=j
                res=sum
            }
        }
    }
    return [res,ind]
}
const maxSubArray2 = (arr) =>{
    let res = arr[0]
    let maxEnding = arr[0]
    for (let i = 1; i < arr.length; i++) {
        // const element = arr[i];
        maxEnding = Math.max(maxEnding+arr[i],arr[i])
        res= Math.max(maxEnding,res)
        
    }
    return res
}

let a = [2, 3, -8, 7, -1, 2, 3]
// a=[-2, -4]
const res= maxSubArray(a)
const res2= maxSubArray2(a)
console.log(res,res2);
