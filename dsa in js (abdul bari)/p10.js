//  Trees

function Node(x,left=null,rigth=null){
    this.val=x
    this.left=left
    this.rigth=rigth
}

function insert(){

}

function create(arr){
     t = new Node(arr[0])
    let i =1
    let q = []
    q.push(t)
    let ele = arr[i]
    while( arr.length>i){
        let p=q.shift()
        if(arr[i]!=-1){
            let s = new Node(arr[i])
            q.push(s)
            p.left = s
        }
        i++
        if(arr[i]!=-1){
            let s = new Node(arr[i])
            q.push(s)
            p.rigth = s
        }
        i++


        

    }
    // console.log(t);
    
}


function preOrder(node){
    let t = ''
    if(node){
        // console.log(node.val);
        t = node.val + preOrder(node.left) + preOrder(node.rigth)
        // preOrder(node.left);
        // preOrder(node.rigth)
        
    }
    return t
}

function iterativePreOrder(node){
    let t = ''
    let x = node
    let s = []
    s.push(x)
    while(s.length!=0){
        t+=s[s.length-1].val
        // s[s.length-1]=s[s.length-1].left
        if(s[s.length-1].left){
            s.push(s[s.length-1].left)
        }
       else{
            let z = s.pop()
            while(!z.rigth && s.length!=0){
                z=s.pop()
            }
            if(z.rigth){
                    s.push(z.rigth)
            }
           

        }
   

    }
    console.log(t);
    
}
function iterativePreOrder2(node){
    let t = ''
    let x = node
    let s = []

   while(x || s.length!=0){
    if(x){
        t+=x.val
        s.push(x)
        x=x.left
        

    }else{
        x=s.pop()
        x=x.rigth
    }
   }
    console.log(t);
    
}
function iterativeInOrder2(node){
    let t = ''
    let x = node
    let s = []

   while(x || s.length!=0){
    if(x){
       
        s.push(x)
        x=x.left
        

    }else{
        x=s.pop()
        t+=x.val
        x=x.rigth
    }
   }
    console.log(t);
    
}
function iterativePostOrder2(node){
    let t = ''
    let x = node
    let s = []

   while(x || s.length!=0){
    if(x){
       
        s.push(x)
        x=x.left
        

    }else{
        x=s.pop()
        // t+=x.val
        if(!x.res){
            s.push({res:x})
            x=x.rigth

        }else{
            t+=x.res.val
            x=null
        }
    }
   }
    console.log(t);
    
}

function levelOrder(node){
    let q = []
    let t = node.val
    q.push(node)
    while(q.length!=0){
        let z = q.shift()
        if(z.left){
            t+=z.left.val



            q.push(z.left)
            // q.push(z.rigth)
            
        }
        if(z.rigth){
            t+=z.rigth.val
            // q.push(z.left)
            q.push(z.rigth)
            
        }
    }

    console.log(t)
}

function countNodes(node){
    
    if(node){
        return countNodes(node.left)+countNodes(node.rigth)+1

    }

    return 0
}






let arr = ['a','b','c','-1','-1','-1','e']
arr = ['a','b','c','d','e','f','g']
let t=null
create(arr)
console.log(t);
const str = preOrder(t)
console.log(str);
iterativePreOrder(t)
iterativePreOrder2(t)
iterativeInOrder2(t)
iterativePostOrder2(t)
levelOrder(t)

let c = countNodes(t)
console.log(`No of Nodes are ${c}`);


