function firstMin(arr){
    let n = arr.length

    let min = arr[0]
    let res = 0
    for(let i=0;i<n;i++){
        min = Math.min(min,arr[i])
        res = Math.max(res,arr[i]-min)

    }
    console.log(res);
    
    
}


let s = '7 10 1 3 6 9 2'

let a = [7,1,3,4]
a = s.split(' ')
// a = [1,4,5,6]
firstMin(a)