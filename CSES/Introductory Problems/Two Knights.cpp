#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;

    ll cres = 0;
    ll dim = 0;
    for(ll i=1; i<=n; i++){
        ll total = pow(i,2) * (pow(i,2)-1)/2;
        
        total -= dim;
        dim+=cres;
        cres+=8;

        cout << total << endl;
    }
}