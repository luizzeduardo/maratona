#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> bolinha(n);
    vector<string> limpo(n);
    for(int i=0; i<n; i++){
        cin >> bolinha[i];
    } 
    for(int i=0; i<n; i++){
        cin >> limpo[i];
    } 

    int resp = 0;

    for(int i=0; i<m; i++){
        set<char> usados;
        for(int j=0; j<n; j++){
            usados.insert(bolinha[j][i]);
        }
        bool tem = true;
        for(int j=0; j<n; j++){
            if(usados.find(limpo[j][i]) != usados.end()) tem = false;
        }

        if(tem) resp++;
    }

    cout << resp << endl;
}