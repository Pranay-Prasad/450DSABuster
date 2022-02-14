// Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mp;
    for(int i = 0; i < n;i++){
        mp[arr[i]]++;
    }
    int count = n/k;
    vector<int>vec;
    for(auto m:mp){
        if(m.second > count){
            vec.push_back(m.first);
        }
    }
    for(auto x:vec){
        cout<<x<<" ";
    }
    return 0;
}
