#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;


// dp classico
// subseq com restrição de caracteres consecutivos diferentes.
int main() {
    string s;
    cin >> s;
    long long dp[3] = {0,0,0}; // a==0, b==1, c==2
    
    for (char letra : s) {
        int idx = letra - 'a';
        long long sum_novo = (dp[0] + dp[1] + dp[2] - dp[idx]) % mod;
        if (sum_novo < 0) sum_novo += mod;
        dp[idx] = (dp[idx] + sum_novo + 1) % mod;
    }
    
    long long ans = (dp[0] + dp[1] + dp[2]) % mod;
    cout << ans << endl;
    
    return 0;
}