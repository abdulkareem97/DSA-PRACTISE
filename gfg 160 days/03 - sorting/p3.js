function inversionCount(arr) {
  let c = 0;
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[i] > arr[j]) c++;
    }
  }
  return c;
}

function mergeAndCount(arr, l, mid, h) {
  let i = l,
    j = mid + 1,
    n1 = mid - l + 1,
    count = 0;
  let c = [];
  while (i <= mid && j <= h) {
    if (arr[i] <= arr[j]) {
      c.push(arr[i++]);
    } else {
      c.push(arr[j++]);
      count += n1 - i + l;
    }
  }
  while (i <= mid) c.push(arr[i++]);
  while (j <= h) c.push(arr[j++]);
  let k = l
  for (let i = 0; i < c.length; i++) {
    arr[k++] = c[i]
  }
  if(l==4 && h==7){
    console.log(count)
  }
  return count
}

function mergeSort(arr, l, r) {
  let res = 0;
  if (l < r) {
    let mid = Math.floor((l + r) / 2);
    // console.log(l,mid,r)
    res += mergeSort(arr, l, mid);
    res += mergeSort(arr, mid + 1, r);
    res += mergeAndCount(arr, l, mid, r);
  }
  return res;
}

function inversionCount1(arr) {
  let x = [...arr];
  let res = mergeSort(x, 0, arr.length - 1);
  console.log(x.join(' '))
  return res;
}

let arr = [2, 4, 1, 3, 5];
// arr = [2, 3, 4, 5, 6];
// arr = [10, 10, 10];
s='24 18 38 43 14 40 1 54'

// 24 18 38 43 14 40 1 54 l=0 , h = 7
//  24 18 38 43  14 40 1 54
// 24 18 - 38 43    14 40 - 1 54
// 24 - 18

// 18 24 38 43 14 40 1 54   ---  14 40 1 54       2 
//  1 0 0 0       n1=2 , i=4
// 18 24 38 43    
//  0              
arr = s.split(' ').map((ele)=>parseInt(ele))
console.log(inversionCount(arr));
console.log(inversionCount1(arr));
