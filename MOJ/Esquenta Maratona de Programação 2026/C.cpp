#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        ll t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
}