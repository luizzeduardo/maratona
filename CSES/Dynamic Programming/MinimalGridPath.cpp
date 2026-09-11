#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n;
    cin >> n;
 
    vector<string> grid(n);
 
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }

    vector<char> resp;
    vector<vector<pair<int, int>>> cands (2*n - 1);
    cands[0].push_back(make_pair(0,0));
    resp.push_back(grid[0][0]);

    for (int d = 1; d <= 2*n - 2; d++){
        vector<char> seen(n, 0);                 
        for (auto [pi, pj] : cands[d-1]){
            if (pi + 1 < n && !seen[pj]){        
                seen[pj] = 1;
                cands[d].push_back({pi + 1, pj});
            }
            if (pj + 1 < n && !seen[pj + 1]){    
                seen[pj + 1] = 1;
                cands[d].push_back({pi, pj + 1});
            }
        }

        char melhor = CHAR_MAX;
        for (auto [i,j] : cands[d]) melhor = min(melhor, grid[i][j]);

        vector<pair<int,int>> filtrado;
        for (auto [i, j] : cands[d])
            if (grid[i][j] == melhor)
                filtrado.push_back({i, j});
        cands[d] = move(filtrado);
        resp.push_back(melhor);
    }

    for (char c : resp) cout << c;
    cout << "\n";
    
}