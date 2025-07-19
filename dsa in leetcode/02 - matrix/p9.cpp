// Kth element in Matrix
#include <iostream>
#include<queue>
#define MAX 5
using namespace std;


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          pq.push(mat[i][j]);
          if(pq.size()>k){
              pq.pop();
          }
      }
  }
  return pq.top();
}

int main() {
    
    return 0;
}
