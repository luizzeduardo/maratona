#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    //sempre maximilizar o b

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll sum = 0;
        vector<ll> a(n);
        vector<ll> b(n);
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }
        for(ll i=0; i<n; i++){
            cin >> b[i];
            if(b[i] < a[i]){
                b[i] += a[i];
                a[i] = b[i] - a[i];
                b[i] -= a[i];
            }
            sum += b[i];
        }

        ll max = INT_MIN;
        for(ll i= 0; i<n; i++){
            if(max < a[i]){
                max = a[i];
            }
        }
        sum += max;
        cout << sum << endl;

    }
}