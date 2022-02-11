// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&vec,int l,int mid,int r){
    int inv = 0;
    int l1 = mid-l+1;
    int l2 = r-mid;
    int arr[l1],brr[l2];
    for(int i = 0; i < l1;i++){
        arr[i] = vec[l+i];
    }
    for(int i = 0; i < l2;i++){
        brr[i] = vec[mid+i+1];
    }
    int i = 0,j = 0,k = l;
    while(i < l1 && j < l2){
        if(arr[i] <= brr[j]){
            vec[k] = arr[i];
            i++,k++;
        }
        else{
            vec[k] = brr[j];
            inv += l1-i; 
            j++,k++;
        }
    }
    while(i < l1){
        vec[k] = arr[i];
        i++,k++;
    }
    while(j < l2){
        vec[k] = brr[j];
        k++,j++;
    }
    return inv;

}
int solve(vector<int>&vec,int l,int r){
    int ans = 0;
    if(l < r){
        int mid = (l+r)/2;
        ans += solve(vec,l,mid);
        ans += solve(vec,mid+1,r);
        ans += merge(vec,l,mid,r);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0;i<n;i++){
        cin>>vec[i];
    }
    cout<<solve(vec,0,n-1)<<endl;
    return 0;
}