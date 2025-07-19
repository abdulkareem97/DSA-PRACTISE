function  search(pat, txt) {
    // your code here
    let arr = []
    for(let i=0;i<txt.length;i++){
        let j=0,k=i
        while(i<txt.length && txt[i]==pat[j]){
            i++
            j++
        }
        if(j==pat.length){
            arr.push(k)
            i=k+1
        }
        else{
            i=k
        }
    }
    return arr
}

function generateLps(pat,lps){
    let m = pat.length
    let i = 1,len=0
    lps[0]=0
    while(i<m){
        if(pat[i]==pat[len]){
            len++
            lps[i]=len
            i++
        }else{
            if(len!=0){
                len = lps[len-1]
            }else{
                lps[i]=0
                i++
            }
        }
    }
}
function search1(pat,txt){
    let n = txt.length
    let m = pat.length
    let lps = new Array(m).fill(0)
    generateLps(pat,lps)
    // console.log(lps)
    let i=0,j=0,res=[]
    while(i<n){
        if(txt[i]==pat[j]){
            i++
            j++
            if(j==m){
                res.push(i-j)
                j=lps[j-1]
            }
        }else{
            if(j!=0){
                j=lps[j-1]
            }else{
                i++
            }

        }
    }
    return res
}

let txt = "abcaab", pat = "ab"
txt = "aabaacaadaabaaba", pat = "aaba"
txt='beeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadedcaceeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeceeaaeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeaceeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadedeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeeeeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeceeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeebabdebaaeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadebaeeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeaeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceadeaeeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceade'
pat='eeeceabeebadbcaeddddaebeebbeaaaebebabccebbabcdadbdaccadaabdedaceade'
console.log(search(pat,txt))
console.log(search1(pat,txt))