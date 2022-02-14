// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int j = -1;
    for(int i = 0; i < n;i++){
        if(arr[i] < a){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    for(int i = 0; i < n;i++){
        if(arr[i] >= a && arr[i] <= b){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}