#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> moedas(n);
    for(int i=0; i<n; i++){
        cin >> moedas[i];
    }

    sort(moedas.begin(), moedas.end());

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int moeda : moedas){
        for(int i=1; i<x+1; i++){
            if(i-moeda < 0) continue; 
            dp[i] = (dp[i] + dp[i - moeda]) % mod;
        }
    }

    cout << dp[x] << endl;

}