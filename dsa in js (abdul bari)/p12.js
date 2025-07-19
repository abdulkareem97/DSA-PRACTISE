// AVL Tree

function Node(x, heigth = 1, left = null, rigth = null) {
  this.val = x;
  this.heigth = heigth;
  this.left = left;
  this.rigth = rigth;
}

function createBst(arr) {
  let tree = new Node(arr[0]);

  for (let i = 1; i < arr.length; i++) {
    // insert(tree,arr[i])
    tree = recursiveInsert(tree, arr[i]);
  }
  return tree;
}

function heigthOfNode(t) {
  let x, y;
  x = t && t.left ? t.left.heigth : 0;
  y = t && t.rigth ? t.rigth.heigth : 0;

  return Math.max(x, y) + 1;
}
function balanceFactorOfNode(t) {
  let x, y;
  x = t && t.left ? t.left.heigth : 0;
  y = t && t.rigth ? t.rigth.heigth : 0;

  return x - y;
}

function inOrder(t) {
  let x = "";
  if (t) {
    x += inOrder(t.left) + " " + t.val + " " + inOrder(t.rigth);
  }
  return x;
}

function recursiveInsert(t, value) {
  if (!t) {
    t = new Node(value);
    return t;
  }
  if (value < t.val) {
    t.left = recursiveInsert(t.left, value);
  } else {
    t.rigth = recursiveInsert(t.rigth, value);
  }
  t.heigth = heigthOfNode(t);
  if (balanceFactorOfNode(t) == -2 && balanceFactorOfNode(t.rigth) == -1) {
    return RRrotation(t)
  }
  else if(balanceFactorOfNode(t) == 2 && balanceFactorOfNode(t.left) == 1){
    return LLrotation(t)
  }
  else if(balanceFactorOfNode(t) == 2 && balanceFactorOfNode(t.left) == -1){
    t.left = RRrotation(t.left)
    return LLrotation(t)
  }
  else if(balanceFactorOfNode(t) == -2 && balanceFactorOfNode(t.rigth) == 1){
    t.rigth = LLrotation(t.rigth)
    return RRrotation(t)
  }
  return t;
}
function inOrderSuccessor(t){
    let x = t.rigth
    while(x && x.left){
        x=x.left
    }
    return x
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
        let suc = inOrderSuccessor(t)
        t.val=suc.val
        t.rigth=deleteNodegfg(t.rigth,value)

    }
    console.log(t.val);
    
    t.heigth = heigthOfNode(t);
    console.log(t.heigth,balanceFactorOfNode(t),balanceFactorOfNode(t.rigth));
    
  if (balanceFactorOfNode(t) <= -2 && balanceFactorOfNode(t.rigth) <= 0) {
    return RRrotation(t)
  }
  else if(balanceFactorOfNode(t) >= 2 && balanceFactorOfNode(t.left) > 0){
    console.log('called');
    
    return LLrotation(t)
  }
  else if(balanceFactorOfNode(t) >= 2 && balanceFactorOfNode(t.left) <= 0 ){
    t.left = RRrotation(t.left)
    return LLrotation(t)
  }
  else if(balanceFactorOfNode(t) <= -2 && balanceFactorOfNode(t.rigth) > 0){
    t.rigth = LLrotation(t.rigth)
    return RRrotation(t)
  }

    return t
}

function RRrotation(t){
    let tr = t.rigth
    t.rigth = tr.left
    tr.left = t
    t.heigth = heigthOfNode(t);
    tr.heigth = heigthOfNode(tr);    
    return tr
}
function LLrotation(t){
    let tl = t.left
    t.left = tl.rigth
    tl.rigth = t
    t.heigth = heigthOfNode(t);
    tl.heigth = heigthOfNode(tl);    
    return tl
}

let arr2 = [10, 20, 30, 40, 50,60,5,2];
// arr2  = [30,20,10] // LL - Rotation
// arr2 = [10, 20, 30] // RR - Rotation
// arr2 = [30, 10, 20] // LR - Rotation
// arr2 = [10, 30, 20] // RL - Rotation
arr2 = [10,20,30,25,28,27,5]
let t2 = createBst(arr2);
// console.log(t2);
t2=deleteNodegfg(t2,5)
t2=deleteNodegfg(t2,10)


console.log('----------------------------');
t2=deleteNodegfg(t2,20)


console.log(inOrder(t2),t2);
