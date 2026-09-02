#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;
    vector<ll> vacas(n);
    for(int i=0; i<n; i++){
        cin >> vacas[i];
    }

    vector<ll> prefix(n+1, 0);
    for(int i=1; i<=n; i++){
        prefix[i] += prefix[i-1]+vacas[i-1];
    }

    ll maior = 0;

    vector<ll> restos(7, -1);
    restos[0] = 0;

    for(int i=1; i<=n; i++){
        ll resto = prefix[i]%7;
        if(restos[resto] != -1){
            ll novo = i - restos[resto];
            maior = max(maior, novo);
        }

        if(restos[resto] == -1) restos[resto] = i;

    }

    cout << maior << endl;
}