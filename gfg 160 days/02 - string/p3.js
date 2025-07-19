function areAnagrams(s1, s2) {
    s1=s1.split('').sort().join('')
    s2=s2.split('').sort().join('')
    return s1==s2
}
function areAnagrams1(s1, s2) {
    let obj={}
    for(let i of s1){
        obj[i]=(obj[i]||0)+1
    }
    for(let i of s2){
        obj[i]=(obj[i]||0)-1
    }
    for(let key in obj){
        if(obj[key]!=0){
            return false
        }
    }
    return true
}
function areAnagrams2(s1, s2) {
    let arr = new Array(26).fill(0)
    for(let c of s1){
        arr[c.charCodeAt(0)-'a'.charCodeAt(0)]++
    }
    for(let c of s2){
        arr[c.charCodeAt(0)-'a'.charCodeAt(0)]--
    }
    for(let c of arr){
        if(c!=0){
            return false
        }
    }
    return true
    

}

let s1 = "geeks", s2 = "kseeg"

console.log(areAnagrams(s1,s2))
console.log(areAnagrams1(s1,s2))
console.log(areAnagrams2(s1,s2))