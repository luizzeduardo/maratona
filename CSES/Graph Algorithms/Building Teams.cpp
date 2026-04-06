#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool> visto(n, false);
    vector<int> dist(n, 0);
    queue<int> lista;
    
    bool valido = true;
    
    for (int i = 0; i < n; i++) {
        if (!visto[i]) {
            lista.push(i);
            visto[i] = true;
            dist[i] = 0;
            
            while (valido && !lista.empty()) {
                int val = lista.front();
                lista.pop();
                
                for (int vizinho : adj[val]) {
                    if (visto[vizinho]) {
                        if (dist[val] % 2 == dist[vizinho] % 2) {
                            valido = false;
                            break;
                        }
                    } else {
                        visto[vizinho] = true;
                        dist[vizinho] = dist[val] + 1;
                        lista.push(vizinho);
                    }
                }
            }
        }
        if (!valido) break;
    }
    
    if (!valido) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << dist[i] % 2 + 1 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}