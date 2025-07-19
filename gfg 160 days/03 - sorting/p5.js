function insertInterval(intervals, newInterval) {
    let x = [...intervals],z=-1
    for(let i=0;i<x.length;i++){
        // console.log(x[i])
        if(newInterval[0]<x[i][0]){
            // console.log
            // x.splice(i,0,newInterval)
            z=i
            break
        }
    }
    let res = []
    res.push(x[0])
    // console.log(z)
    let i = 1
    if(z==0){
        i=0
        res[0]=newInterval
        z=-2
    }
    for(;i<x.length;i++){
        // console.log(cur,last)
        // if(z==0){
        //     // console.log(cur,i)
        //     z=-2
        //     i--
        //     res[0]=newInterval
        // }
        let last = res[res.length-1]
        let cur = x[i]
     
        if(z==i){
            cur = newInterval
            z=-1
            i--
            // console.log(cur,i)
        }
  
        if(cur[0]<=last[1]){
            res[res.length-1][1] = Math.max(last[1],cur[1])
        }else{
            res.push(cur)
        }
    }
    return res
}

function insertInterval1(intervals, newInterval) {
    let res = [];
    let i = 0;
    const n = intervals.length;

    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push(intervals[i]);
        i++;
    }

    // Merge all overlapping intervals with the new interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push(newInterval);

    // Add all the remaining intervals
    while (i < n) {
        res.push(intervals[i]);
        i++;
    }

    return res;
}

let  intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
// intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
intervals = [ [ 1, 3 ], [ 10, 15 ], [ 20, 30 ] ] , newInterval = [5,6]
// intervals = [[0,40]],newInterval=[80,97]
// intervals = [[1,5]],newInterval=[0,3]
console.log(insertInterval(intervals,newInterval))
console.log(insertInterval1(intervals,newInterval))