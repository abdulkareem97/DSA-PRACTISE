// Smallest Positive Missing



function missingNumber(arr) {
  let n = arr.length;
  for (let i = 0; i < n; i++) {
    while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
      let val = arr[i] - 1;
      [arr[i], arr[val]] = [arr[val], arr[i]];
    }

  }
  for(let i=0;i<n;i++){
    if(arr[i]!=i+1){
        return i+1
    }
  }
  return n+1
}
function missingNumber1(arr) {
  let n = arr.length;
  let visited = Array(n+1).fill(false)
  for(let i=0;i<n;i++){
    if(arr[i]>=1 && arr[i]<=n){
        visited[arr[i]] = true
    }
  }
  for(let i=1;i<=n;i++){
    if(!visited[i]){
        return i
    }
  }
  return n+1
}
function missingNumber2(arr) {
  let n = arr.length;
  let br = [...arr]
  br.sort((a,b)=>a-b)
//   console.log(arr);
  
  let res = 1
  for(let i=0;i<n;i++){
    if(br[i]==res){
        res++
    }else if(br[i]>res){
        return res
    }
  }
  return n+1
}

let arr = [2, -3, 4, 1, 1, 7];
arr=[1,2,3,4,5]
// arr = [2,-3,1,4,1,7]
// arr = [1,-3,2,4,1,7]
// arr = [1,2,-3]
console.log(missingNumber1(arr));
console.log(missingNumber2(arr));
console.log(missingNumber(arr));

//  2 5 10 15
//  k = 1
// 13

// 3 4
// 4 3
// 14 5
