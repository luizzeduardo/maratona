#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<ll> prefix(n+1, 0);
    for(int i=1; i<=n; i++){
        prefix[i] += prefix[i-1] + a[i-1];
    }

    map<ll, ll> freqPrefix;
    freqPrefix[0] = 1;


    ll resposta = 0;
    for(int i=1; i<=n; i++){
        resposta += freqPrefix[prefix[i] - x];

        freqPrefix[prefix[i]]++;
    }

    cout << resposta << endl;
}