// Sorting


// swap

// 1. Bubble Sort

function bubbleSort(arr){
    for(let i=0;i<arr.length-1;i++){
        let flag = 0
        for(let j=0;j<arr.length-1-i;j++){
            
            if(arr[j]>arr[j+1]){
                
                [arr[j],arr[j+1]]=[arr[j+1],arr[j]]
                flag=1
            }
            
            
        }
        
        if(flag==0){
            break
        }
    }
}


// Insertion Sort
function insertionSort(arr){
    for(let i=1;i<arr.length;i++){
        let ele = arr[i]
        let j = i-1
        while(j>-1 && ele<arr[j]){
            arr[j+1]=arr[j]
            j--



        }
        arr[j+1]=ele
    }
}

// 3. Selection Sort
function selectionSort(arr){
    for(let i=0;i<arr.length;i++){
        let k=i
        for(let j=k;j<arr.length;j++){
            if(arr[j]<arr[k]){
                k=j
            }
        }
        [arr[k],arr[i]]=[arr[i],arr[k]]
    }
}

// 4. Heap Sort
function heapify(arr,n,i){
    let largest = i
    let left = 2*i+1
    let rigth = 2*i+2
    while(left<n && arr[left]>arr[largest]){
        largest=left
    }
    
    while(rigth<n && arr[rigth]>arr[largest]){
        
        largest=rigth
    }
    if(largest!=i){
        // console.log('hello');
        
        [arr[largest],arr[i]]=[arr[i],arr[largest]]
        heapify(arr,n,largest)
    }

}
function heapSort(arr){
    for(let i=Math.floor(arr.length/2)-1;i>=0;i--){
        heapify(arr,arr.length,i)
    }
    for(let i=arr.length-1;i>=0;i--){
        [arr[0],arr[i]]=[arr[i],arr[0]]
        heapify(arr,i,0)

    }
}

// 5. Quick Sort
function partition(arr,l,h){
  
    
    let pivot = arr[l-1]
    let i=l,j=h
    while(i<j){
        while(arr[i]<pivot){
            i++
        }
        while(arr[j]>pivot){
            j--
        }
        if(i<j)
        [arr[i],arr[j]]=[arr[j],arr[i]]
    }
    // console.log(i,j);
    
    [arr[l-1],arr[j]]=[arr[j],arr[l-1]]
    return  j
}

function quickSort(arr,l,h){
    if(l<h){
        let j= partition(arr,l,h)
        quickSort(arr,l,j-1)
        quickSort(arr,j+2,h)
        

    }
}

// 6. Merge Sort
function merge(a,l,mid,h){
    let i=l,j=mid+1,k=l
    let c = []
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            c.push(a[i++])
        }else{
            c.push(a[j++])
        }
    }
    while(i<=mid){
        c.push(a[i++])
    }
    while(j<=h){
        c.push(a[j++])
    }
    k=0
    for(let i=l;i<=h;i++){
        a[i]=c[k++]     
    }
}
function mergeSortIterative(arr){
    let p
    for(p=2;p<=arr.length;p*=2){
        for(let i=0;i+p-1<arr.length;i+=p){
            let l=i,h=i+p-1
            let mid = Math.floor((l+h)/2)
            
            merge(arr,l,mid,h)
        }
        
    }
    if(p/2<arr.length){
        merge(arr,0,p/2-1,arr.length-1)
    }
}
function mergeSortRecursive(arr,l,h){
   if(l<h){
    let mid = Math.floor((l+h)/2)
    mergeSortRecursive(arr,l,mid)
    mergeSortRecursive(arr,mid+1,h)
    merge(arr,l,mid,h)
   }
  
}

// 7. Count Sort
function countSort(arr){
    let max = arr[0],k=0
    for(let i=1;i<arr.length;i++){
        if(max<arr[i]){
            max=arr[i]
        }
    }
    let c = new Array(max+1).fill(0)
    for(let i=0;i<arr.length;i++){
        c[arr[i]]++
    }
    for(let i=0;i<c.length;i++){
        while(c[i]!=0){
            arr[k++]=i
            c[i]--
        }
    }
}

// 8. Bucket/Bin Sort
function Node(val,next=null){
    this.val=val
    this.next=next
}
function insert(n,val){
    let t = n
    if(!t){
        t=new Node(val)
        return t
    }
    while(t.next){
        t=t.next
    }
    t.next=new Node(val)
    return n
}

function binSort(arr){
    let max = arr[0],k=0
    for(let i=1;i<arr.length;i++){
        if(max<arr[i]) max = arr[i]
    }
    let bin = new Array(max+1).fill(null)
    for(let i=0;i<arr.length;i++){
        bin[arr[i]]=insert(bin[arr[i]],arr[i])
    }
    for(let i=0;i<bin.length;i++){
        while(bin[i]){
            arr[k++]=bin[i].val
            bin[i] = bin[i].next
        }
    }

}

// 9. Radix Sort
function radixSort(arr){
    let max = arr[0]
    for(let i=1;i<arr.length;i++){
        if(max<arr[i]) max = arr[i]
    }
    for(let j=1;Math.floor(max/j)>0;j*=10){
        let r =  Array.from({length:10},()=>[])  
        for(let i=0;i<arr.length;i++){
            let num = Math.floor(arr[i]/j)%10
            r[num].push(arr[i])           
        }
        let k=0
        for(let i=0;i<10;i++){
            while(r[i].length>0){
                arr[k++]=r[i].shift()
            }
        }
        
    }
    
}

// 10. Shell Sort
function shellSort(arr){
    print(arr)
    // let gap=1
    for(let gap=Math.floor(arr.length/2);gap>0;gap=Math.floor(gap/2)){
        for(let i=gap;i<arr.length;i++){
            let ele = arr[i]
            let j=i-gap
            while(j>-1 && arr[j]>ele){
                arr[j+gap]=arr[j]
                j-=gap
            }
            arr[j+gap]=ele
        }
    }
}

function print(arr){
    console.log(arr.join(' '))
}

let arr = [8,5,7,3,2]
// arr.unshift
bubbleSort(arr)
// console.log(arr)

arr = [8,5,7,3,2]
insertionSort(arr)
// console.log(arr)

arr = [8,5,7,3,2]
selectionSort(arr)
// console.log(arr)

arr = [8,5,7,3,6]
heapSort(arr)
// console.log(arr)

arr = [8,5,7,3,6]
arr= [11,13,7,12,16,9,24,5,10,3]
quickSort(arr,1,arr.length-1)
// console.log(arr)

let a = [2,10,18,20,23,29]
let b = [4,9,19,25]
// let c = merge(a,b)
// arr = [2,10,18,20,23,29,4,9,19,25]
// arr=[10,2]
arr= [11,13,7,12,16,9,24,5,10,3]
// mergeSortIterative(arr)
mergeSortRecursive(arr,0,arr.length-1)
// console.log(arr)

arr= [11,13,7,12,16,9,24,5,10,3]
countSort(arr)
// console.log(arr)

arr= [11,13,7,12,16,9,24,5,10,3,11]
// arr=[1,1]
binSort(arr)
// console.log(arr)

arr= [11,13,7,12,16,9,24,5,10,3,11,100]
// arr=[1,1]
radixSort(arr)
// console.log(arr)

arr= [11,13,7,12,16,9,24,5,10,3,11,100]
// arr = [8,7]
shellSort(arr)
// print(arr)


arr = [9999,5,4,3,2,1]
partition(arr,1,5)
print(arr)
