function  minRemoval(intervals) {
    
    let count = 0
    let x  = [...intervals]
    x.sort((a,b)=>a[0]-b[0])
    console.log(x)
    let end = x[0][1]
    for(let i=1;i<x.length;i++){
        if(end>x[i][0]){
            count++
            end = Math.min(x[i][0],end)
            
        }else{
            end = x[i][1]

        }
    }
    return count

}


let intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]

// 1 2 1 3 2 3 3 4
// 
console.log(minRemoval(intervals))