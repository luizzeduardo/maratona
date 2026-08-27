#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
 
        // produtividade
        vector<ll> a(n);
        for(int i=0; i<n ;i++){
            cin >> a[i];
        } 
 
 
        // prefix sum dos intervalos    
        vector<ll> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] += prefix[i] + a[i];
        }
 
        // motivacional
        vector<ll> b(m);
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
 
        // O(logn)
        sort(b.begin(), b.end());
 
        //o(n)
        ll melhor = 0;
        ll prev = 0;
        for(ll x : b){
            ll seg_sum = prefix[x] - prefix[prev];
            melhor += abs(seg_sum);
 
            prev = x;       
        }
 
        if(prev < n){
            melhor+= prefix[n] - prefix[prev];
        }
 
        cout << melhor << endl;
 
        
 
 
    }
}