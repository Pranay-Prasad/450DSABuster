//Write a program to reverse an array or string
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
    int n;//number of elements in array
    cin>>n;
    int arr[n];
    // 1 2 3 4 5 6
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0; i < (n/2);i++){
        swap(arr[i],arr[n-i-1]);
    }
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    // Time complixity O(n),  space complixity O(1) {excluding Input array};
    return 0;
}