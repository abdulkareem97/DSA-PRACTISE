function isPalindrome(s,i,j){
    while(i<j){
        if(s[i]==s[j]){
            i++
            j--
        }else{
            return false
        }
    }
    return true
}


function minChar(s) {
//    let a= isPalindrome('abac',0,2)
//    console.log(a)
    let count = 0
    let n = s.length
    let i = n-1
    while(i>=0 && !isPalindrome(s,0,i)){
         count++
        i--
    }
    return count
}
function minChar1(s) {
//    let a= isPalindrome('abac',0,2)
let s1 = s+'$'+s.split('').reverse().join('')
let m = s1.length,n=s.length
    let arr = Array(m).fill(0)
    let i=1,len=0
    while(i<m ){
        if(s1[i]==s1[len]){
            len++
            arr[i]=len
            i++
        }else{
            if(len!=0){
                len=arr[len-1]

            }else{
                arr[i]=0
                i++
            }

        }
    }
    return n-arr[m-1]
    
}

let s = "abc"
s="aacecaaaada"

console.log(minChar(s))
console.log(minChar1(s))
// let arr = Array(s.length).fill(0)
// generateLps(s,arr)
// console.log(arr)
