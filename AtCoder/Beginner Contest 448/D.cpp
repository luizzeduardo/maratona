#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    //fazer um DFS com um vecotr de freq
    vector<int> arvore(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arvore[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> resposta(n + 1, false);
    set<int> caminho;
    vector<int> pai(n + 1, -1);

    stack<pair<int, int>> stk;
    stk.push({1, 0});

    while (!stk.empty()) {
        auto [u, estado] = stk.top();
        stk.pop();
        
        if (estado == 0) {
            // Entrando no nó
            int tamanhoAntes = caminho.size();
            caminho.insert(arvore[u]);
            
            // Se o tamanho não mudou, valor já existia
            if (caminho.size() == tamanhoAntes) {
                resposta[u] = true;
            } else {
                if (pai[u] != -1) {
                    resposta[u] = resposta[pai[u]];
                }
            }
            
            stk.push({u, 1});
            
            for (int v : g[u]) {
                if (v == pai[u]) continue;
                pai[v] = u;
                stk.push({v, 0});
            }
        } else {
            caminho.erase(arvore[u]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << (resposta[i] ? "Yes" : "No") << "\n";
    }
}