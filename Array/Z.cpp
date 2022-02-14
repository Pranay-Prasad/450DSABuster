// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    set<int>s;
    for(int i = 0; i < n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    int m;
    cin>>m;
    int brr[m];
    bool ans = true;
    for(int i = 0; i < m;i++){
        cin>>brr[i];
        if(!s.count(brr[i])){
            ans = false;
        }
    }
    (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}