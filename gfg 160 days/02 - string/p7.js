function   areRotations(s1, s2) {
    // code here
    let n = s2.length
    let j=0
    while(j<n){
        if(s1==s2){
            return true
        }
        let k = s2[0]
        s2 = s2.split('')
        for(let i=0;i<n-1;i++){
            s2[i]=s2[i+1]
        }
        s2[n-1]=k
        s2=s2.join('')
        // console.log(s2[n-1])
        j++

    }
    return false

}

function constructLps(s,lms){
    let n = s.length
    let i=1,len=0
    while(i<n){
        if(s[i]==s[len]){
            s[i++]=++len
        }else{
            if(len!=0){
                len = lms[len-1]
            }else{
                s[i++]=0
            }
        }
    }
}

function   areRotations1(s1, s2) {
    // code here
    let i=0;j=0
    s1 = s1+s1
    let n = s1.length,m=s2.length
    let arr = Array(n).fill(0)
    // let arr1 = Array(n).fill(0)
    constructLps(s1,arr)
    // constructLps(s2,arr1)
    while(i<n){
        if(s1[i]==s2[j]){
            i++
            j++
            if(j==m){
                return true
            }
        }else{
            if(j!=0){
                j=arr[j-1]
            }else{
                i++
            }
        }
    }
    return false
    

}

let s1 = "abcd", s2 = "cdab"
// 


s1 = "aab", s2 = "aba"
s1 = "abcd", s2 = "acbd"

// abac   acab

console.log(areRotations(s1,s2))
console.log(areRotations1(s1,s2))