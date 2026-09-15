#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >>a[i];
    vector<pair<ll, ll>> totalRep(n);
    set<ll> unicos;
    map<ll, ll> quant;
    map<ll, pair<ll, ll>> ultimo;

    for(int i=0; i<n; i++){
        if(quant[a[i]] == 0){
            ultimo[a[i]].second = i;
        } 

        totalRep[i].first = unicos.size();
        totalRep[i].second = quant[a[i]];


        unicos.insert(a[i]);
        quant[a[i]]++;


        ultimo[a[i]].first = ultimo[a[i]].second;
        ultimo[a[i]].second = i;

    }



    ll total = 0;
    for(auto[chave, valor] : ultimo){
        if(quant[chave] < 2) continue;

        //cout << chave << endl;
        ll local = totalRep[valor.first].first;

        // cout << totalRep[valor.first].second << endl;

        if(totalRep[valor.first].second > 0) local--;

        total+= local;
    }

    cout << total << endl;
}