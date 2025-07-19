

function testing(n,a,b,c){
    if(n==0) return
    testing(n-1,a,c,b)
    console.log(`Move ${n} from ${a} - ${c} using ${b}`)
    testing(n-1,b,a,c)

}

testing(2,'a','b','c')