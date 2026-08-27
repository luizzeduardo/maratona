#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
constexpr int mod = 1000000007;
 
int main(){
    int t;
    cin >> t;
 
    // de quantas formas posso fazer ix2
    ll n = 1000000;
    vector<vector<ll>> dp(n+1, vector<ll> (2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(ll i=1; i<n; i++){
 
        dp[i+1][0] += (4*dp[i][0] + dp[i][1])%mod;
        dp[i+1][1] += (2*dp[i][1] + dp[i][0])%mod;
 
    }
 
 
    while(t--){
        ll num;
        cin >> num;
        
 
 
        cout << (dp[num][0]+dp[num][1])%mod << endl;
 
    }
}