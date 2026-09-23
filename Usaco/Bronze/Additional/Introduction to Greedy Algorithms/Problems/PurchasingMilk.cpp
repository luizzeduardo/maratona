#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// x <= 10^9 -> 2^y
// y <= 30

ll binpow(ll a, ll b){
    ll total = 1;
    while(b>0){
        if(b&1){
            total*=a;
        }
        a *= a;
        b >>= 1;
    }

    return total;
}


ll f(ll n, ll falta, vector<ll> &valores, vector<ll> &pots){

    ll total = 0;
    if(falta <= 0) return 0;

    // maior
    if(falta > pots[n-1]){
        total += valores[n-1]*(falta/pots[n-1]);
        falta %= pots[n-1];
    }

    int i = 0;
    // binary search?? over se pa
    while(falta > pots[i]){
        i++;
    }
    if(i == 0) return valores[0];

    ll a = valores[i];
    ll b = valores[i-1] + f(n, falta-pots[i-1], valores, pots);

    total += min(a, b);

    return total;
}


int main(){
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> deals(n);
    for(int i=0; i<n; i++){
        cin >> deals[i];
        if(i>0){
            deals[i] = min(deals[i], deals[i-1]*2);
        }
    }

    vector<ll> valores(31);
    valores[0] = deals[0];
    ll potencia = 31;
    int maior = min(potencia, n);
    for(int i=1;i<31;i++){
        ll cand = 2*valores[i-1];
        if(i < n) cand = min(cand, deals[i]);
        valores[i] = cand;
    }

    vector<ll> pots(31);
    pots[0] = 1;
    for(int i=1; i<31; i++){
        pots[i] = pots[i-1]*2; 
    }

    while(q--){
        ll query;
        cin >> query;

        cout << f(potencia, query, valores, pots) << endl;

    }
    

}