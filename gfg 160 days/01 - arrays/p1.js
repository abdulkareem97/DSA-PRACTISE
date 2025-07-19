// Maximum Product Subarray


// Native Approach
function maxProduct(arr) {
    // code here
    let n = arr.length
    let result = arr[0]
    let maxInd = [0,0]
    for(let i=0;i<n;i++){
        let mul = 1
        for(let j=i;j<n;j++){
            mul*=arr[j]
            if(mul>result){
                result = mul
                maxInd = [i,j]
            }
        }
    }
    return [result,maxInd.join(' ')]
}

// Using minimum and maximum product ending at any index - O(n) Time and O(1) Space
function max(a,b,c){
    return a>b ? (a>c ? a : c) : (b>c ? b : c)
}
function min(a,b,c){
    return a<b ? (a<c ? a : c) : (b<c ? b : c)
}
function maxProduct1(arr){
    let curMinProd = arr[0]
    let curMaxProd = arr[0]
    let maxProd = arr[0]
    for(let i=1;i<arr.length;i++){
        let temp = max(arr[i],arr[i]*curMaxProd,arr[i]*curMinProd)
        curMinProd = min(arr[i],arr[i]*curMaxProd,arr[i]*curMinProd)
        curMaxProd = temp
        maxProd = max(maxProd,curMaxProd,curMinProd)
    }
    return maxProd
}
function maxProduct2(arr){
    let leftToRight = 1
    let rightToLeft = 1
    let maxProd = arr[0]
    for(let i=0;i<arr.length;i++){
        if(leftToRight==0) leftToRight=1
        if(rightToLeft==0) rightToLeft=1
        leftToRight*=arr[i]
        let j = arr.length-i-1
        rightToLeft*=arr[j]
        maxProd = max(maxProd,leftToRight,rightToLeft)
    }
    return maxProd
}

const arr = [-2, 6, -3, -10, 0, 2];
console.log(maxProduct(arr));
console.log(maxProduct1(arr));
console.log(maxProduct2(arr));