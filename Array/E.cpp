// Move all the negative elements to one side of the array ;
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
    int j = 0;
    for(int i = 0; i < n;i++){
        if(arr[i] < 0){
            if(i != j){
                swap(arr[j],arr[i]);
            }
            j++;
        }
    }
    for(auto x:arr){
        cout<<x<< " ";
    }
    return 0;
}