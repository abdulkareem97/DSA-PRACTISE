// Count Inversions
// Difficulty: MediumAccuracy: 16.93%Submissions: 625K+Points: 4
// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.

#include <iostream>
#include<vector>
using namespace std;

    int merge(vector<int> &arr,int l,int mid,int h){
        int i=l,j=mid+1,count=0;
        vector<int> v;
        // cout<<" l "<<l<<" h "<<h<<" count ";
        while(i<=mid && j<=h){
            if(arr[i]<=arr[j]){
                v.push_back(arr[i++]);
            }else{
                count+= mid - i + 1;
                v.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            // count++;
                v.push_back(arr[i++]);
        }
        while(j<=h){
                v.push_back(arr[j++]);
        }
        for(int k=0;k<v.size();k++){
            arr[l++] = v[k];
        }
        // cout<<count<<endl;
        // if(h-mid-1==0 && count!=0){
        //     return count-1;
        // }
        return count;
    }
    int mergeSort(vector<int> &arr,int l,int h){
        int c = 0;
        if(l<h){
            int mid = (l+h)/2;
            // c+=mergeSort(arr,l,mid);
            // c+=mergeSort(arr,mid+1,h);
            c = mergeSort(arr,l,mid) + mergeSort(arr,mid+1,h);
            return c + merge(arr,l,mid,h);
        }
        return c;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr,0,arr.size()-1);
    }

int main() {
    
    return 0;
}
