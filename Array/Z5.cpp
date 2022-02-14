// Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    int count = 0;
    for(int i = 0; i < n;i++){
        int num = 0;
        int t = arr[i];
        while(t > 0){
            num = num*10 + t%10;
            t = t/10;
        }
        if(num == arr[i]){
            count++;
        }
    }
    (count == n)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}