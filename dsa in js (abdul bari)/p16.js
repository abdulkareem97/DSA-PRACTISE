// Graph



let z = Infinity;


let arr  =  [ 
     [0,0,0,0,0,0,0,0] ,
    [0,0,1,1,1,0,0,0],
    [0,1,0,1,0,0,0,0],
    [0,1,1,0,1,1,0,0],
    [0,1,0,1,0,1,0,0],
    [0,0,0,1,1,0,1,1],
    [0,0,0,0,0,1,0,0],
    [0,0,0,0,0,1,0,0]   ]

function bfs(arr,i,n){
    let q=[],visited=new Array(n+1).fill(0),t=''
    // console.log(i);
    t+=i+' '
    q.push(i)
    visited[i]=1
    while(q.length!=0){
        let u = q.shift()
        for(let v=1;v<=n;v++){
            if(arr[u][v]==1 && visited[v]==0){
                // console.log(v)
                t+=v+' '
                q.push(v)
                visited[v]=1
            }
        }
    }
    console.log('BFS From ',i,' is ',t);
    
}

function dfs(arr,i,n,visited){
    if(visited[i]==1) return ''
    let t = ''
    // console.log(i);
    t+=i+' '
    visited[i]=1
    for(let v=1;v<=n;v++){
        if(arr[i][v]==1){
           t+= dfs(arr,v,n,visited)
        }
    }
    return t
}


// Prims Algorithm

function prims(cost,n){
    let min = z,u,v;
    for(let i=1;i<=n;i++){
        for(let j=1;j<n;j++){
            if(min>cost[i][j]) {
                // console.log(i,j,min,cost[i][j])
                min = cost[i][j]
                u=i
                v=j
            }
        }
    }
    let edges = [ [ 0,0 ] , [0,0] , [0,0] , [0,0] , [0,0] ,[0,0] ]
    edges[0][0] = u
    edges[0][1] = v
    let rear = Array(n+1).fill(z)
    rear[u] = rear[v] = 0
    for(let i=1;i<=n;i++){
        if(rear[i]!=0){
            if(cost[i][u]<cost[i][v]){
                rear[i] = u
            }else{
                rear[i] = v
            }
        }
    }
    // console.log(rear)
    for(let i=1;i<n-1;i++){
        let min = z,k=0;
        for(let j=1;j<=n;j++){
            if(rear[j]!=0){
                // console.log(i)
                if(min>cost[j][rear[j]]){
                    k=j
                    min = cost[j][rear[j]]
                }
            }
        }
        edges[i][0] = k
        edges[i][1] = rear[k]
        rear[k]=0

        for(let j=1;j<=n;j++){
            if(rear[j]!=0){
                if(cost[j][rear[j]] > cost[j][k]  ){
                    rear[j] = k
                }
            }
        }

        // console.log(rear.join(' '),' => ',k)
    }

    let c =0
    for(let i=0;i<n-1;i++){
        console.log(edges[i][0]," - ",edges[i][1]," costs -> ",cost[edges[i][0]][edges[i][1]])
        c+=cost[edges[i][0]][edges[i][1]]
    }
    console.log('Total Cost is ',c)



}


// Kruskals algorithm

function union(s,a,b){
    if(s[a]<s[b]){
        s[a] = s[a]+s[b]
        s[b] = a
    }else{
        s[b] = s[a]+s[b]
        s[a] = b
    }
}

function find(s,a){
    while(s[a]>0){
        a = s[a]
    }
    return a
}

function createEdges(arr,edge){
    for(let i=1;i<arr.length;i++){
        for(let j=i+1;j<arr.length;j++){
            if(arr[i][j]!=z){
                // console.log(i,j,arr[i][j])
                edge.push([i,j,arr[i][j]])
            }
        }
    }
}

function kruskals(arr,n) {
    let s = new Array(n+1).fill(-1);
    let ans = []
    let edges = []
    createEdges(arr,edges)
    let include = new Array(edges.length).fill(false)
    let i=0
    while(i<n-1){
        let min = [z,z,z]
        let ind = -1
        for(let j=1;j<edges.length;j++){
            let k = edges[j]
            if(!include[j] && min[2]>k[2] ){
                min = k
                ind = j
            }
        }
        // console.log(min)
        include[ind] = true
        if(find(s,min[0])!=find(s,min[1])){
     
            // console.log(min[0],min[1])
            union(s,find(s,min[0]),find(s,min[1]))
            ans.push([...min])
            i++
        }
       
    }
    let c =0
    for(let i=0;i<ans.length;i++){
        console.log(ans[i][0]," - ",ans[i][1]," costs -> ",arr[ans[i][0]][ans[i][1]])
        c+=arr[ans[i][0]][ans[i][1]]
    }
    console.log('Total Cost is ',c)
    
}

let arr1 = [
    [0,0,0,0,0,0,0,0],
    [0,z,25,z,z,z,5,z],
    [0,25,z,9,z,z,z,6],
    [0,z,9,z,10,z,z,z],
    [0,z,z,10,z,12,z,11],
    [0,z,z,z,12,z,18,16],
    [0,5,z,z,z,18,z,z],
    [0,z,6,z,11,16,z,z]
]

// prims(arr1,7)
kruskals(arr1,7);




let i = 7,n=7
// bfs(arr,i,n)

// let d=dfs(arr,i,n,new Array(n+1).fill(0))
// console.log('DFS From ',i," is ",d)

