// Given an array arr[] of N integers, calculate the median
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0 ; i < n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int mid = n/2;
    if(n%2 != 0){
        cout<<vec[mid]<<endl;
    }
    else{
        cout<<(vec[mid]+vec[mid-1])/2<<endl;
    }
    return 0;
}