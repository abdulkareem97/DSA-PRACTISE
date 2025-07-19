function sort012(arr) {
    let x = [...arr]
    x.sort((a,b)=>a-b)
    return x.join('')
}
function sort0121(arr) {
    let x = [...arr]
    // x.sort((a,b)=>a-b)
    let c0=0,c1=0,c2=0
    for(let i=0;i<x.length;i++){
        if(x[i]==0) c0++
        else if(x[i]==1) c1++
        else c2++
    }
    let i=0
    while(c0>0){
        x[i++]=0
        c0--
    }
    while(c1>0){
        x[i++]=1
        c1--
    }
    while(c2>0){
        x[i++]=2
        c2--
    }
    return x.join('')
}
function sort0122(arr) {
    let x = [...arr]
    // x.sort((a,b)=>a-b)
    let l=0,m=0,h=arr.length-1
    while(m<=h){
        if(x[m]==0){
            [x[l],x[m]]=[x[m],x[l]]
            l++
            m++
        }else if(x[m]==1){
            m++
        }else{
            [x[m],x[h]] = [x[h],x[m]]
            h--
        }
    }
    
    return x.join('')
}

let arr = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
// 0 0 1
// arr = [0,0,1]
console.log(sort012(arr))
console.log(sort0121(arr))
console.log(sort0122(arr))
