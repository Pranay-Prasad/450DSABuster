// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n-1;i++){
        for(int j = 0; j < n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}