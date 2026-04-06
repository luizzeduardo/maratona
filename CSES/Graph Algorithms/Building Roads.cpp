#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visitado(n, false);
    vector<int> grupos;
    stack<int> stk;

    for(int i=0; i<n; i++){
        if(!visitado[i]){
            grupos.push_back(i);
            stk.push(i);
            visitado[i] = true;

            while(!stk.empty()){
                int curr = stk.top();
                stk.pop();

                for (int vizinho : adj[curr]) {
                    if (visitado[vizinho]) continue;
                    visitado[vizinho] = 1;
                    stk.push(vizinho);
                }
            }

        }
    }


    int k = grupos.size() - 1;
    cout << k << endl;

    for(int i=0; i<grupos.size()-1; i++){
        cout << grupos[i]+1 << " " << grupos[i+1]+1 << endl;
    }
}