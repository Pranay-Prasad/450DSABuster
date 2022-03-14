//Kruskal's algo (Spaning tree)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        // cout<<"set"<<endl;
        make_set(i);
    }
    cout<<"ENTER n and M"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i = 0; i < m;i++){
        cout<<"X>>y>>z>>"<<endl;
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({z,x,y});
    }
    sort(edges.begin(),edges.end());
    int ans = 0;
    for(auto i:edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y) continue;
        else{
            cout<<u<<" "<<v<<"\n";
            ans += w;
            union_sets(u,v);
        }
    }
    cout<<ans<<endl;
    return 0;
}