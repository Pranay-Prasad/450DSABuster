// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i = 0;  i < n;i++){
        cin>>arr[i];
    }
    bool ans = false;
    sort(arr,arr+n);
    for(int k = 0; k < n-2;k++){
        int i = k+1;
        int j = n-1;
        while(i < j){
            if((arr[i]+arr[j]+arr[k]) == x){
                ans = true;
                break;
            }
            else if((arr[i]+arr[j]+arr[k])>x){
               j--;
            }  
            else
                i++;
        }
    }  
    (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl; 
    return 0;
}