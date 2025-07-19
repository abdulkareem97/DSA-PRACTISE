function maxDif(arr, start, end) {
    let res = 0
    // let i =7
    // {
    for(let i=start;i<end;i++){
        let curRes = 0
        for(let j=i+1;j<end;j++){
            if(a[j]>a[i]){
                let cur = (a[j]-a[i]) + maxDif(arr,start,i)
                // let cur1 = a[j]-a[i]
                res = Math.max(res,cur)
                // curRes = Math.max(curRes,cur1)
            }
        }
        // console.log(`From ${i}-${arr[i]} is ${curRes} `)
    }
    // console.log(`Max Profit From ${start}-${arr[start]} To ${end-1}-${arr[end-1] || 0} is ${res}`)
    return res
}

const maxDif2 = (arr) => {
    let n = arr.length
    let lmin =lmax = arr[0]
    let i=0
    let res=0
    while(i<n-1){
        while(i<n-1 && arr[i]>arr[i+1]){i++}
        lmin = arr[i]
        // console.log('local minima',lmin)
        while(i<n-1 && arr[i]<arr[i+1]){i++}
        lmax = arr[i]
        // console.log('local maxima',lmax)
        res+=lmax-lmin
        i++
    }
    return res
}

const maxDif3 = (arr)=>{
    let res=0
    let n = arr.length-1
    for(let i=0;i<n;i++){
        if(arr[i]<arr[i+1]){
            res+=arr[i+1]-arr[i]
            
        }
    }

    return res
}


let a = [10, 20, 30, 40, 3, 4, 2, 6];
a.reverse()
a=[100, 180, 260, 40, 535, 50, 700]
a=[100, 180, 170, 310, 40, 535, 695]
a=[100, 180, 260, 310, 300, 535, 695]
// a=[4,2,2,2,4]
// a=[100,695]
// a=[1,3,2,4]
const maxProfit = maxDif(a, 0, a.length);
const maxP = maxDif2(a)
const maxP3 = maxDif3(a)
console.log(maxProfit,maxP,maxP3);
// console.log(310-100,695-300,210+395,695-100)

