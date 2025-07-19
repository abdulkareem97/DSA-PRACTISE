function hIndex(citations) {
    let x = [...citations]
    x.sort((a,b)=>b-a)
    let h=0,i=0
    while(i<x.length && x[i]>i){
        i++
    }
    return i
}
function hIndex1(citations) {
    let x = [...citations]
    let arr = Array(x.length).fill(0)
    for(let i=0;i<x.length;i++){
        // console.log(x[i],arr.join(''))
        if(x[i]>=x.length) arr[x.length-1]++
        else
        arr[x[i]]++
    }
    let i = arr.length-1
    let freq = arr[i]
    console.log(arr,i)
    // i=5 6
    while(freq<i){
        i--
        freq+=arr[i]
        // console.log(freq,i)
    }
    
    return i

}

let citations =  [5, 0, 2, 0, 2]
//  5 2 2 0 0
citations = [6, 0, 3, 5, 3]
// 0 3 3 5 6
let s = '8 12 10 12 9 12'
citations = s.split(' ')
console.log(hIndex(citations))
console.log(hIndex1(citations))