// Binary Search Tree

function Node(x,left = null, rigth = null) {
  this.val = x;
  this.left = left;
  this.rigth = rigth;
}

function create(arr) {
  t = new Node(arr[0]);
  let i = 1;
  let q = [];
  q.push(t);
  let ele = arr[i];
  while (arr.length > i) {
    let p = q.shift();
    if (arr[i] != -1) {
      let s = new Node(arr[i]);
      q.push(s);
      p.left = s;
    }
    i++;
    if (arr[i] != -1) {
      let s = new Node(arr[i]);
      q.push(s);
      p.rigth = s;
    }
    i++;
  }
  // console.log(t);
}

function inOrder(t) {
  let x = "";
  if (t) {
    x += inOrder(t.left) + " " + t.val + " " + inOrder(t.rigth);
  }
  return x;
}
function bst(t, key) {
  // console.log(t.val)
  if (!t) {
    return null;
  }
  if (t.val == key) {
    return t;
  }
  if (key < t.val) {
    return bst(t.left, key);
  } else {
    return bst(t.rigth, key);
  }
}
function bstIterative(t, key) {
  // console.log(t.val)
  let x = t;
  while (x) {
    if (x.val == key) {
      return x;
    } else if (key < x.val) {
      x = x.left;
    } else {
      x = x.rigth;
    }
  }
  return null;
}

function insert(t, value) {
  let r = null,
    x = t;
  while (x) {
    r = x;
    if (x.val == value) {
      return;
    } else if (value < x.val) {
      x = x.left;
    } else {
      x = x.rigth;
    }
  }
  if (value < r.val) {
    r.left = new Node(value);
  } else {
    r.rigth = new Node(value);
  }
}

function recursiveInsert(root,t, value) {
  if (!t) {
    t = new Node(value);
    return t;
  }
  if (value < t.val) {
    t.left = recursiveInsert(root,t.left, value);
  } else {
    t.rigth = recursiveInsert(root,t.rigth, value);
  }

  return t;
}

function createBst(arr) {
  let tree = new Node(arr[0]);

  for (let i = 1; i < arr.length; i++) {
    // insert(tree,arr[i])
    tree=recursiveInsert(tree,tree, arr[i]);
  }
  return tree;
}

function createBstPreOrder(arr){
    let s = []
    let i=0
    let tree = new Node(arr[i++])
    // s.push(tree)
    let x= tree
    while(i<arr.length){
        let range = s.length==0 ? Infinity : s[s.length-1].val
        // console.log(arr[i]);
        
        if(arr[i]<x.val){
            x.left = new Node(arr[i++])
            s.push(x)
            x=x.left
        }else if(arr[i]>x.val && arr[i]<range){
            x.rigth = new Node(arr[i++])
            s.push(x)
            x=x.rigth
        }else{
            x=s.pop()
        }
    }
    // console.log(tree);
    
    return tree
}

function inOrderPreceder(t){
    let x = t
    while(x && x.rigth){
        x=x.rigth
    }
    return x
}
function inOrderSuccessor(t){
    let x = t
    while(x && x.left){
        x=x.left
    }
    return x
}

function deleteNode(t,value){
    if(!t){
        return null
    }
    if(!t.left && !t.rigth){
        return null
    }
    if(value<t.val){
        t.left=deleteNode(t.left,value)
    }else if(value>t.val){
        t.rigth=deleteNode(t.rigth,value)
    }else{
        if(t.left){
            let q=inOrderPreceder(t.left)
            t.val=q.val
            t.left=deleteNode(t.left,value)

        }
       else{
            let q=inOrderSuccessor(t.rigth)
            t.val=q.val
            t.rigth=deleteNode(t.rigth,value)

        }
    }

    return t
}
function deleteNodegfg(t,value){
    if(!t){
        return t
    }
    if(value<t.val){
        t.left=deleteNodegfg(t.left,value)
    }else if(value>t.val){
        t.rigth=deleteNodegfg(t.rigth,value)
    }else{
        if(!t.left){
            return t.rigth
        }
        if(!t.rigth){
            return t.left
        }
        let suc = inOrderSuccessor(t.rigth)
        t.val=suc.val
        t.rigth=deleteNodegfg(t.rigth,value)

    }

    return t
}

function heigthOfNode(t){
    let x,y
    if(t)
    {
        x = heigthOfNode(t.left)
        y = heigthOfNode(t.rigth)
        if(x>y){
            return x+1
        }else{
            return y+1
        }

    }
    return 0
}


let arr = [30, 20, 40, 10, 25, 35, 50];
let t = null;
create(arr);
// console.log(inOrder(t));
// console.log(bst(t,30))
// console.log(bstIterative(t,30));
insert(t, 5);
insert(t, 55);
// console.log(inOrder(t));

let arr2 = [10, 20, 30, 40, 50, 60,5];
let t2 = createBst(arr2);

// console.log(inOrderPreceder(t2.left));
// deleteNode(t2,10)
console.log(inOrder(t2));
// console.log(t2);


let arr3 = [100,200,150,160,155];
let t3 = createBst(arr3);
// deleteNode(t3,200)
// deleteNodegfg(t3,200)
// console.log(t3);

console.log(inOrder(t3));

let arr4 = [30,20,10,15,25,40,50,45];
let t4 = createBstPreOrder(arr4);
// console.log(t4);

// console.log(inOrder(t4));


