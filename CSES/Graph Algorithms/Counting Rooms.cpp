#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> mov = {{0,1}, {1,0}, {-1, 0}, {0,-1}};

    vector<string> mapa(n);
    for(int i=0; i<n; i++){
        cin >> mapa[i];
    }
    vector<vector<bool>> visitado(n, vector<bool>(m, false));

    int salas = 0;

    for(int i=0 ; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mapa[i][j] == '.' && !visitado[i][j]){
                salas++;

                stack<pair<int, int>> stk;
                stk.push({i, j});
                visitado[i][j] = true;

                while(stk.size()){
                    int x = stk.top().first;
                    int y = stk.top().second;
                    stk.pop();

                    for(int k=0; k<4; k++){
                        int prox = x + mov[k].first;
                        int proy = y + mov[k].second;
                        if(prox >= 0 && prox < n && proy >=0 && proy < m){
                            if(mapa[prox][proy] == '.' && !visitado[prox][proy]){
                                visitado[prox][proy] = true;
                                stk.push({prox, proy});
                            }
                        }
                    }
                }
            }
        }
    }

    cout << salas << endl;

}