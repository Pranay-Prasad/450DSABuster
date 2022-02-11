// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    set<int> s;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            s.insert(A[i]);
            i++, j++, k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    for (auto x : s)
    {
        ans.push_back(x);
    }
    return ans;
}
int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int A[n1], B[n2], C[n3];
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> C[i];
    }
    vector<int> ans = solve(A, B, C, n1, n2, n3);
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}