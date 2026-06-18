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
    string s;
    cin >> s;
    ll n = s.size();

    // precomputa essa porra dos fatoriais
    vector<ll> fact(n+1);
    fact[0] = 1;
    for(ll i=1; i<=n; i++){
        fact[i] = (fact[i-1] * i )% mod;
    }


    ll freq[26] = {};
    fill_n(freq,26, 0);
    for( char c : s){
        freq[c - 'a']++;
    }


    ll total = fact[n];

    for(ll i=0; i<26; i++){
        if(freq[i]>1){
            total = total*inv_mod(fact[freq[i]]) % mod;
        }
    }


    cout << total << endl;


}