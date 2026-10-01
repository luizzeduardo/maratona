#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> paint(n);
    for(int i=0; i<n; i++) cin >> paint[i];

    set<char> cores;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(paint[i][j] != '0') cores.insert(paint[i][j]);
        }
    }

    map<char, pair<int, int>> menor;
    map<char, pair<int, int>> maior;
    //o(N^3), para N<=10, -> 1000 
    for(char cor: cores){
        int minL = INT_MAX;
        int minH = INT_MAX;
        int maxL = INT_MIN;
        int maxH = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(paint[i][j] == cor){
                    minL = min(minL, i);
                    maxL = max(maxL, i);
                    minH = min(minH, j);
                    maxH = max(maxH, j);
                }
            }
        }
        menor[cor] = {minL, minH};
        maior[cor] = {maxL, maxH};
    }

    //ver se tem intersecção
    // se não tem com nenhum outro -> +1
    // se tem apenas se ele não sobrepor nenhum
    set<int> naoPrimeiro;
    for(char cor: cores){
        for(int i=menor[cor].first; i<=maior[cor].first; i++){
            for(int j=menor[cor].second; j<=maior[cor].second; j++){
                if(paint[i][j] != cor) naoPrimeiro.insert(paint[i][j]);
            }
        }
    }

    cout << cores.size() - naoPrimeiro.size() << endl;

}