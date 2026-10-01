#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n;
    cin >> n;
    int m;
    cin >> m;

    // temos n pastos e m vacas
    // queremos uma combinaçaõ onde os 2 pastos preferidos de cada vaca sejam diferentes
    // no maximo 3 vacas gostam de um pasto

    vector<vector<int>> pastos(n);
    vector<vector<int>> vacas(m);
    vector<int> foi(n, false);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        vacas[i].push_back(a);
        vacas[i].push_back(b);
        pastos[a].push_back(i);
        pastos[b].push_back(i);
    }

    vector<int> resposta(n, 0);
    //itera sobre as vacas
    for(int i=0; i<n; i++){
        vector<bool> pode(4, true);
        for(int vaca: pastos[i]){
            int j;
            if(vacas[vaca][0] == i){
                j =1;
            }
            else j=0;
            int viz = vacas[vaca][j];     
            int val = resposta[viz];      
            if(val > 0){
                pode[val-1] = false;
            }
        }
        for(int j=0; j<4; j++){
            if(pode[j]) {resposta[i]=j+1; break;}
        }
    }

    for(int i=0; i<n; i++) {
        if(resposta[i] == 0) cout << 1;
        else cout << resposta[i];
    }
    cout << endl;
}