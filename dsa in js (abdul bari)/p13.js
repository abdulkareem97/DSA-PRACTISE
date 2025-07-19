// Heap - Binary Heap

function insert(arr,n){
    let i = n
    let ele = arr[n]
    while(i>0 && ele>arr[Math.floor((i-1)/2)]){
       arr[i]=arr[Math.floor((i-1)/2)]
       i=Math.floor((i-1)/2)
    }
    arr[i]=ele
}

function insertHeapify(arr,n){
    // console.log(arr,n);
    
    let i = n
    let ele = arr[n]
    // console.log(ele,n)
    while(arr[2*i+1]){
        if(ele<arr[2*i+1] || ele<arr[2*i+2]){
                if(!arr[2*i+2] || arr[2*i+1]>arr[2*i+2]){
                    [arr[i],arr[2*i+1]]=[arr[2*i+1],arr[i]]
                    i=2*i+1
                }else{
                    [arr[i],arr[2*i+2]]=[arr[2*i+2],arr[i]]
                    i=2*i+2
                }
        }else{
            break
        }
    }
}

function createHeap(arr){
    // for(let i=1;i<arr.length;i++){
       
    //     insert(arr,i)
    // }
    for(let i=arr.length-1;i>=0;i--){
       
        insertHeapify(arr,i)
    }
    // console.log(arr)
}

function deleteElement(a,n){
    // let n=a.length-1
    let x = a[0]
    a[0] = a[n]
    let i=0,j=2*(i)+1
    while(j<n){
        if(a[j+1]>a[j]){
            j++
        }

        if(a[i]<a[j]){
            let temp = a[i]
            a[i] = a[j]
            a[j] = temp
            i=j
            j=2*i+1
        }else{
            break
        }
    }
    a[n]=x
    
}

function heapSort(a){
    createHeap(a)
    for(let i=a.length-1;i>0;i--){
        deleteElement(a,i)
    }
}

// let x= [30,20,15,5,10,12,6,40,35]
// x=[40,35,30,15,10,25,5]
let arr = [40,35,30,15,10,25,5]
// arr.push(40)
// insert(arr)
// arr.push(35)
// insert(arr)
// createHeap(arr,x)
// // deleteElement(arr)
// console.log(arr)
// deleteElement(arr)
// console.log(arr)

createHeap(arr)
// console.log(arr)
// deleteElement(arr,arr.length-1)
// console.log(arr)

heapSort(arr)
// console.log(arr)

let x = [30,20,15,5,10,12,6,40,35]
// createHeap(x)
// deleteElement(x,8)
// deleteElement(x,7)
// deleteElement(x,6)
// deleteElement(x,5)
// deleteElement(x,4)
// deleteElement(x,3)
// deleteElement(x,2)
// deleteElement(x,1)

// console.log(x)
// deleteElement(x,2)
heapSort(x)


console.log(x)

let z = [40,30,35,15,10,5]
deleteElement(z,z.length-1)
// console.log(z)

let a1 = [2,3]
// insertHeapify(a1,0)
// console.log(a1)


