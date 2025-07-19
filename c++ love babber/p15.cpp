// Binary Search Advance Program
// concept search space(answer) -> minimize

#include <iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[], int m, int n, int val)
{
    int stu = 1, pages = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>val) return false;
        if(arr[i]+pages>val){
            stu++;
            pages=arr[i];
            // cout<<stu<<endl;
            if(stu>m) return false;
        }else{
            pages+=arr[i];
        }
    }

    return true;
}

int bookAllocation(int arr[],int m,int n){
   int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int min = arr[0] , max = sum,ans=-1;
    while(min<=max){
        int mid = (min+max)/2;
        // cout<<" mid value "<<mid<<" min value "<<min<<" max value "<<max<<endl;
        // int ans = 
        if(isPossible(arr,m,n,mid)){
            ans = mid;
            max = mid-1;
        }else{
            min = mid+1;
        }
    }
    // int x = 7;
    return ans;
}



// Painter Pattern
// exactly above answer

// Aggressive Cow
bool isPossibleAC(int arr[],int n,int k,int val)
{
    int cowCount = 1,place=arr[0];
    // cout<<" in ac";
    for(int i=1;i<n;i++){
        // cout<<" place value "<<place<<" array "<<arr[i]<<endl;
        if(arr[i]-place>=val){
            // cout<<" here ";
            place = arr[i];
            cowCount++;
            if(cowCount==k) return true;
        }
    }
    return false;
}

int aggressiveCow(int arr[],int n,int k){
    int max = arr[0],ans = -1;
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    int min = 0;
    // isPossibleAC(arr,n,k,3);
    while(min<=max){
        int mid = (min+max)/2;
        //  cout<<" mid value "<<mid<<" min value "<<min<<" max value "<<max<<endl;
        if(isPossibleAC(arr,n,k,mid)){
            ans = mid;
            min = mid+1;
        }else{
            max = mid - 1;
        }
    }
    return ans;
}

// Cooking Ninjas

bool isPossibleCN(int arr[],int n,int p,int time){
    int parathas = 0;
    for(int i=0;i<n;i++){
        int t=0,k=0;
        while( t + arr[i]*(k+1) <=time){
            k++;
            t+=arr[i]* k ;
        }
        // cout<<t<<endl;
        parathas+=k;
        if(parathas>=p) return true;
    }
    return false;
}

int cookingNinjas(int arr[],int n,int p){
        int min = 0 ,max = 20,ans=-1;


        while(min<=max){
            int mid = (min+max)/2;
            // cout<<" mid value "<<mid<<" min value "<<min<<" max value "<<max<<endl;
            if(isPossibleCN(arr,n,p,mid)){
                ans = mid;
                // return ans;
                max = mid-1;
            }else{
                min = mid+1;
            }
            // break;
        }
        return ans;
}



// lumberjack Mirko Wood Cutting Problem

bool isPossibleLJM(int arr[],int n,int w,int val){
    int woods = 0;
    for(int i=0;i<n;i++){
        if(arr[i]-val>0){
            woods+=arr[i]-val;
            // cout<<" "<<woods<<val;
            if(woods>=w) return true;
        }
    }
    return false;
}


int lumberjackMirko(int arr[],int n,int w){
    int min = 0 , max = arr[0],ans=-1;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    // min = 999;
    // isPossibleLJM(arr,n,15,w);
    while(min<=max){
        int mid = (min+max)/2;
        if(isPossibleLJM(arr,n,w,mid)){
            ans = mid;
            min = mid+1;
        }else{
            // cout<<"here "<<mid;
            max = mid-1;
        }
    }
    return ans;

}


int main()
{
    int arr[] = {0,0,0,0,0};
    int n = sizeof(arr) / sizeof(int);
    int m = 4;
    cout<<boolalpha;
    // cout << isPossible(arr, m, n, 80)<<endl;
    int ans = bookAllocation(arr,m,n);
    // int ans = painterPattern(arr,m,n);
    // cout<<" "<<ans;

    // int arr1[] = {4,2,1,3,6};
    // int cow = 2;
int arr1[] = {1, 10, 20, 30, 100};
int cow = 3;
    int sarr1 = sizeof(arr1)/sizeof(int);
    sort(arr1,arr1+sarr1);
    // int ans1 = aggressiveCow(arr1,sarr1,cow);
    // cout<<" "<<ans1;

    // int arr2[] = {10};
    // int paratha = 1;
    int arr2[] = {1,2,3,4};
    int paratha = 11;
    int sarr2 = sizeof(arr2)/sizeof(int);
    int ans2 = cookingNinjas(arr2,sarr2,paratha);
    cout<<" "<<ans2;

    int arr3[] = {4,42,40,26,46};
    int wood = 20;
    // int arr3[] = {20,15,10,17};
    // int wood = 7;
    int sarr3 = sizeof(arr3)/sizeof(int);
    // int ans3 = lumberjackMirko(arr3,sarr3,wood);
    // cout<<" "<<ans3;

    return 0;
}

