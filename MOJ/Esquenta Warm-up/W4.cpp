#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visto(n+1, false);
    int vans = 0;

    for(int i=1; i<=n; i++){
        if(visto[i]) continue;
        vans++;
        queue<int> fila;
        fila.push(i);
        visto[i] = true;
        while(!fila.empty()){
            int frente = fila.front();
            fila.pop();
            for(int j: adj[frente]){
                if(!visto[j]){
                    visto[j] = true;
                    fila.push(j);
                }
            }
        }
    }

    cout << vans << endl;

}

