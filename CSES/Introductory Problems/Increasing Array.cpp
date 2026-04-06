#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> x(n);
    for(ll i=0; i<n; i++){
        cin >> x[i];
    }

    ll total = 0;
    for(ll i=1; i<n; i++){
        if(x[i] < x[i-1]){
            total += x[i-1] - x[i];
            x[i] = x[i-1];
        }
    }

    cout << total << endl;


}