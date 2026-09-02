#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n; cin >> n;

    vector<pair<string, int>> animais(n);
    vector<vector<string>> caracteristicas(n);
    for(int i=0; i<n; i++){
        cin >> animais[i].first;
        cin >> animais[i].second;

        for(int j=0; j<animais[i].second; j++){
            string carac;
            cin >> carac;
            caracteristicas[i].push_back(carac);
        }
    }

    int maior = 0;
    for(int i=0; i<n; i++){
        int local = 0;
        
        for(int j=0; j<n; j++){

            int esse = 1;
            if(i == j) continue;
            for(string caracteristica: caracteristicas[i]){
                for( string compara: caracteristicas[j]){

                    if(compara == caracteristica){
                        esse++;
                        break;
                    }
                }
            }
        

            local = max(local, esse);

        }

        maior = max(maior, local);

    }

    cout << maior << endl;
}