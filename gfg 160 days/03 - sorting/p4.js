function mergeOverlap(mikel) {
  let arr = [...mikel];
  let ans = [];
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      if (
        i != j &&
        ((arr[i][0] + arr[j][1] == arr[i][1] + arr[j][0] &&
          arr[i][1] >= arr[j][0]) ||
          (arr[i][0] <= arr[j][0] && arr[i][1] >= arr[j][1]))
      ) {
        // console.log('here')
        arr[i][1] = Math.max(arr[i][1], arr[j][1]);
        arr[j] = [0, 0];
      }
    }
  }
  for (let i = 0; i < arr.length; i++) {
    if (arr[i][0] == 0 && arr[i][1] == 0) {
    } else {
      ans.push(arr[i]);
    }
  }
  return ans;
}
function mergeOverlap1(mikel) {
  let arr = [...mikel];
  let res = [];
  arr.sort((a, b) => a[0] - b[0]);
  res.push(arr[0]);
  for (let i = 1; i < arr.length; i++) {
    let last = res[res.length - 1];
    let cur = arr[i];
    if (cur[0] <= last[1]) {
      res[res.length-1][1] = Math.max(last[1], cur[1]);
    } else {
      res.push(cur);
    }
  }
  return res;
}

let arr = [
  [1, 3],
  [2, 4],
  [6, 8],
  [9, 10],
];
arr = [[6,8],[1,9],[2,4],[4,7]]
// arr = [[1,9],[6,8]]

console.log(mergeOverlap(arr));
console.log(mergeOverlap1(arr));
