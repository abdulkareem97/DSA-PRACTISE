function  nonRepeatingChar(s) {
    for(let i=0;i<s.length;i++){
        let occurs = false
        for(let j=0;j<s.length;j++){
            if(s[i]==s[j] && i!=j) occurs = true
        }
        if(!occurs){
            return s[i]
        }
    }
    return -1
}
function  nonRepeatingChar1(s) {
    let obj = {}
    for(let c of s){
        obj[c] = ( obj[c] || 0 ) + 1
    }
    for(let key in obj){
        if(obj[key]==1) return key
    }
    return -1

}
function  nonRepeatingChar2(s) {
    let arr = new Array(26).fill(-1)
    for(let c of s){
        let ind = c.charCodeAt()-'a'.charCodeAt()
        if(arr[ind]!=-1 || arr[ind]==-2){
            arr[ind]=-2
        }else{
            arr[ind]=ind
        }
    }
    let ind = -1
    for(let i=0;i<arr.length;i++){
        if(arr[i]>-1){
            ind = i
            break
        }
    }
    if(ind==-1){
        return -1
    }
    return s[ind]

}

let s = "geeksforgeeks"
// s = "aabbccc"
console.log(nonRepeatingChar(s))
console.log(nonRepeatingChar1(s))
console.log(nonRepeatingChar2(s))