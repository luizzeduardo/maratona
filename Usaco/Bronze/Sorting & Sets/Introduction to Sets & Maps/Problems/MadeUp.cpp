#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];

    vector<ll> cntA(n+1, 0);
    vector<ll> cntB(n+1, 0);

    for(int i=0; i<n; i++){
        cntA[a[i]]++;
        cntB[b[c[i]-1]]++;
    }

    ll total = 0;
    for(int i=1; i<=n; i++){
        total += cntA[i] * cntB[i];
    }


    cout << total << endl;

}