// Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
// Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.
#include<bits/stdc++.h>
using namespace std;
//Unordered
void solve1(vector<int>&vec,int n){
    int i = 0, j = n-1;
    while(i<j){
        while(i < n && vec[i] > 0){
            i++;
        }
        while(j > 0 && vec[j] < 0){
            j--;
        }
        if(i < j){
            swap(vec[i],vec[j]);
        }
    }
    if(j == 0 || i == n){
        return;
    }
    int k = 0;
    while(k < n && i < n){
        swap(vec[k],vec[i]);
        i++;
        k+=2;
    }
}

//Ordered
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for (int i = 0; i < n; i++){
        cin>>vec[i];
    }
    solve1(vec,n);

    for(auto x:vec)
        cout<<x<<" ";
    return 0;
}