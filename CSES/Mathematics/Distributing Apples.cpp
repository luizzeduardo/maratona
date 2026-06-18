#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll power(ll base, ll exp, ll mod){
    ll result = 1;
    while(exp > 0){
        if(exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

ll inv_mod(ll a){
    return power(a, mod-2, mod);
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;

    // precomputa essa porra dos fatoriais
    vector<ll> fact(n+m);
    fact[0] = 1;
    for(ll i=1; i<=n+m-1; i++){
        fact[i] = (fact[i-1] * i )% mod;
    }


    int total = 1;
    total = (fact[n+m-1])%mod * inv_mod(fact[m])%mod * inv_mod(fact[n-1])%mod;

    // permutaçaõ entre n e m 
    // stars and pipes

    // (n + m - 1)!/(m! * (n-1)!)


    cout << total << endl;


}