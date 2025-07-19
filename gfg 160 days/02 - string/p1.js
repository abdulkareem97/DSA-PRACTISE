function atoi(str){
    let idx = 0,res=0,sign=1,n=str.length
    while(idx<n && str[idx]==' ') idx++
    if(idx<n && (str[idx]=='-' || str[idx]=='+')){
        if(str[idx]=='-') sign=-1
        idx++
    }


    while(idx<n && (str[idx]>='0' && str[idx]<='9')){
        if(res>Math.pow(2,31)/10 || (res==Math.floor(Math.pow(2,31)/10) && str[idx]>'7')){

            return sign==1 ? Math.pow(2,31)-1 : -1*Math.pow(2,31)
        }
        res = 10*res+(str[idx]-'0')
        idx++
    }



    return res*sign
}


console.log(atoi('   1231231231311133'))
console.log(atoi('   -2147483648'))
console.log(atoi('   2147483644'))
console.log(atoi('-'))