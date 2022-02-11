// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&vec,int n){
    if(n == 1){
        return 0;
    }
    int ans = 0;
    int i = 0, j = 1;
    while(j < n){
        if(vec[i] < vec[j]){
            ans = max(ans,vec[j]-vec[i]);
        }
        else{
            i = j;
        }
        j++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n;i++){
        cin>>vec[i];
    }
    cout<<solve(vec,n)<<endl;
    return 0;
}