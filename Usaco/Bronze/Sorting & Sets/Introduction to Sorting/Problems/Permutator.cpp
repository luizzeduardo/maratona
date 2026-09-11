
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int j=0; j<n; j++) cin >> b[j];
    
    for(int i=0; i<n; i++){
        ll mult = (ll)(i + 1) * (n - i);
        a[i] *= mult;
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    
    ll total = 0;
    for(int i=0; i<n; i++){
        total += (ll) a[i]*b[i];
    }
    
    cout << total << endl;
}