// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i <n;i++){
        cin>>arr[i];
    }
    set<int>s;
    for(int i = 0; i < n;i++){
        s.insert(arr[i]);
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        if(!s.count(arr[i]-1)){
            int l = 0;
            while(s.count(arr[i]+l)){
                l++;
            }
            ans = max(l,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}