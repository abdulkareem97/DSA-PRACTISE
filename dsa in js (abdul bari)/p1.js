function LinkedList(x,next=null){
    this.val = x
    this.next = next

}

let front=rear=null

function enqueue(x){
    let t = new LinkedList(x)
    if(t==null){
        console.log('Queue is Full');
        
    }else{
        if(front==null){
            front=rear=t
        }    else{
            rear.next = t
            rear = t
        }
    }
}

function dequeue(){
    if(front==null){
        console.log('Queue is Empty');
        
    }
    else{
        front=front.next
    }
}

function display(){
    let head = front
    
    while(head){
        console.log(head.val);
        head = head.next
    }
}


dequeue()
enqueue(5)
enqueue(7)
enqueue(8)
dequeue(
    
)
display()