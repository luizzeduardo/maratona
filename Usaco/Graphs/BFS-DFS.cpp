#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dfs(n);
    vector<int> bfs(n);
    for(int i=0; i<n; i++){
        cin >> bfs[i];
    }
    for(int i=0; i<n; i++){
        cin >> dfs[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<int> pai(n + 1, 0);


    //fazer a dfs
    stack<int> pilha;
    pilha.push(1);   
    pai[1] = 0;

        for (int i = 1; i < n; i++) {
            int curr = dfs[i]; 

            while (!pilha.empty()) {
                int top = pilha.top();
                
        }
    }
}