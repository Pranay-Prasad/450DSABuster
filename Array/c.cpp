//Find the Kth smallest element in array
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int largest(vector<int>&a,int l,int r,int k){
    int p  = a[r];
    int pos = l;
    for(int i = l;i<r;i++){
        if(a[i] <= p){
            swap(a[i],a[pos]);
            pos++;
        }
    }
    swap(a[pos],a[r]);
    if(pos > k) return largest(a,l,pos-1,k);
    else if(pos < k) return largest(a,pos+1,r,k);
    return a[pos];
}
int smallest(vector<int>&a,int l,int r, int k){
    if(k > 0 && k<= r-l+1){
        int p = a[r],i = l;
        for(int j = l;j<=r-1;j++){
            if(a[j] <= p){
                swap(a[i],a[j]);
                i++;
            }
        }
        swap(a[i],a[r]);
        int pos = i;
        if(pos-l == k-1){
            return a[pos];
        }
        if(pos-1 > k-1)
            return smallest(a,l,pos-1,k);
        return smallest(a,pos+1,r,k-pos+l-1);
    }
    return INT_MAX;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    For(i,n) cin>>arr[i];
    cout<<smallest(arr,0,n-1,k)<<endl;
    cout<<largest(arr,0,n-1,n-k)<<endl;
    return 0;
}