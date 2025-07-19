function     mergeArrays(a, b) {
    // code here
    let x = [...a],y=[...b]
    for(let i=y.length-1;i>=0;i--){
        if(y[i]<x[x.length-1]){
            let ele = y[i]
            y[i]=x[x.length-1]
            let k = x.length-2
            while(k>=0 && ele<x[k]){
                x[k+1]=x[k]
                k--
            }
            x[k+1]=ele
        }
    }


    return [x.join(' '),y.join(' ')]

}
function     mergeArrays1(a, b) {
    // code here
    let x = [...a],y=[...b]

    let i=x.length-1,j=0
    while(i>=0 && j<y.length){
        if(x[i]>y[j]){
            [ x[i],y[j] ] = [ y[j],x[i] ]
        }
        i--
        j++
    }
    x.sort((a,b)=>a-b)
    y.sort((a,b)=>a-b)
    return [x.join(' '),y.join(' ')]

}

let a  = [2, 4, 7, 10] , b= [2,3]
// 2 4 7 3
// 3 
// `2 4 7 7
//  2 4 4 7
//  1     5 6 7 8 9
// mergeArrays(a,b)
console.log(mergeArrays(a,b))
console.log(mergeArrays1(a,b))