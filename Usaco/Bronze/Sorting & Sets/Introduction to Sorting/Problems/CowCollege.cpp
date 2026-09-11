#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> pay(n);
    for(int i=0; i<n; i++){
        cin >> pay[i];
    }
    sort(pay.begin(), pay.end());

    ll total = LONG_LONG_MIN;
    ll quant = 0;
    ll val = 0;
    for(int i=n-1; i>=0; i--){
        quant++;
        ll local = pay[i]*quant;
        if(total > local) continue;
        val = pay[i];
        total = local;
    }

    cout << total << " " << val << endl;
}