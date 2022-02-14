// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int s = INT_MIN,e = INT_MIN;
    int i = 0,j = n-1;
    int ans = 0;
    while(i < j){
        s = max(s,arr[i]);
        e= max(e,arr[j]);
        if(arr[i] < arr[j]){
            ans += s-arr[i];
            i++;
        }
        else{
            ans += e-arr[j];
            j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}