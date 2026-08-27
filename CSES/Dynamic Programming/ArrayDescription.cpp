#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1000000007;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    for(ll i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));

    if(nums[0] != 0){
        dp[0][nums[0]] = 1;
    }
    else{
        for(ll i=1; i<=m; i++){
            dp[0][i] = 1;
        }
    }

    for(ll i=1; i<n; i++){
        if(nums[i] == 0){
            for(ll j=1; j<=m; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
                if(j < m){
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
                }
            }
        }
        else{
            dp[i][nums[i]] = (dp[i-1][nums[i]] + dp[i-1][nums[i]-1])%mod;
            if(nums[i] < m){
                dp[i][nums[i]] = (dp[i][nums[i]] + dp[i-1][nums[i]+1])%mod;
            }
        }
    }


    ll sum = 0;
    for(ll i=1; i<=m; i++){
        sum = (sum + dp[n-1][i]) % mod;
    }

    cout << sum << endl;



    //   0 1 2 -> i
    // 0 0 0 0
    // 1 0 1 0
    // 2 1 1 1
    // 3 0 1 0
    // v
    // j
}