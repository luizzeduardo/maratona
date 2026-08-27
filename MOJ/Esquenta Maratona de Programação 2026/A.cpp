#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> questoes(n, 0);
    vector<ll> erros(n, 0);

    ll melhor = 0;
    for(int i=0; i<n; i++){
        cin >> questoes[i];
        cin >> erros[i];
    }


    for(int i=1; i<n; i++){
        if(questoes[i] > questoes[melhor]){
            melhor = i;
        } else if(questoes[i] == questoes[melhor]){
            if(erros[melhor] > erros[i]){
                melhor = i;
            }
        }
    }

    cout << melhor + 1 << endl;


}