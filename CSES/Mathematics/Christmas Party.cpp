#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll power(ll base, ll exp, ll mod){
    ll result = 1;
    while(exp > 0){
        if(exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

ll inv_mod(ll a){
    return power(a, mod-2, mod);
}

//pegar logo os prefix até n
// O(n)
ll caotic_permutation(int n){
    if(n == 0) return 1;
    if(n == 1) return 0;

    vector<ll> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;

    for(int i = 2; i <= n; i++)
        dp[i] = (i - 1) % mod * ((dp[i-1] + dp[i-2]) % mod) % mod;

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    cout << caotic_permutation(n) << endl;
}