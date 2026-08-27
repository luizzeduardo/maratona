#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> penalties(k+1, 0);
    vector<bool> resolved(k+1, false);
    vector<vector<ll>> submissions(n, vector<ll>(3,0)); // minute, problem, veredito;
    for(ll i = 0; i< n; i++){
        ll p, m, v;
        cin >> p >> m >> v;
        submissions[i][0] = m;
        submissions[i][1] = p;
        submissions[i][2] = v;
    }
    
    for(ll i = 0; i< n; i++){
        ll m = submissions[i][0],
            p = submissions[i][1],
            v = submissions[i][2];
        if(resolved[p]) continue;
        if(v == 1){
            penalties[p] += m;
            resolved[p] = true;
        } else{
            penalties[p] += 20;
        }
    }
    ll ans = 0;
    ll resolvedCount = 0;
    for(ll i = 1; i <= k; i++){
        if(resolved[i]){
            ans += penalties[i];
            resolvedCount++;
        } 
    }

    cout << resolvedCount << " " << ans << endl;
}
