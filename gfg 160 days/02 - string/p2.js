function removeLeadingZero(s){
    let index = s.indexOf('1')
    return s.substring(index)
}

function addBinary(s1,s2){
    s1 = removeLeadingZero(s1)
    s2 = removeLeadingZero(s2)
    // console.log(s1,s2)
    let n = s1.length
    let m = s2.length
    if(n<m){
        return addBinary(s2,s1)
    }


    let carry = 0,j=m-1,t=[]
    for(let i=n-1;i>=0;i--){
        let digit1 = s1[i]-'0'
        let sum=digit1+carry
        if(j>=0){
            let digit2 = s2[j]-'0'
            sum+=digit2
            j--
        }
        carry = Math.floor(sum/2)
        t.push(sum%2)
    }
    if(carry==1){
        t.push(1)
    }

    return t.reverse().join('')
}

let s1 = "1101", s2 = "111"
s2='1111111'
// s1 = '1',s2='0'

console.log(addBinary(s1,s2))

// 1101
//  111
//10100

// 