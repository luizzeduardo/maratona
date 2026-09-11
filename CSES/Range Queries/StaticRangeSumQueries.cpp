#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<ll> prefix(n+1, 0);
    for(int i=1; i<=n; i++){
        prefix[i] += prefix[i-1] + a[i-1];
    }
    while(q--){
        ll i, j;
        cin >> i >> j;
        i--; j--;
        cout << prefix[j+1] - prefix[i] << endl;
    }
}