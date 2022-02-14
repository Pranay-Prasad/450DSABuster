// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans = INT_MAX;
    int i = 0, j = m-1;
    while(j < n){
        ans = min(ans,arr[j]-arr[i]);
        i++,j++;
    }
    cout<<ans<<endl;
    return 0;
}