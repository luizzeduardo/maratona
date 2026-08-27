#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> digitos(int num){
    vector<int> digits;
    while(num != 0){
        digits.push_back(num % 10); 
        num /= 10;                   
    }

    return digits;
}

int main(){
    ll n;
    cin >> n;

    vector<ll> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(ll i=1; i<n+1; i++){
        vector<int> digits = digitos(i);
        for(int digito: digits){
            if(i-digito<0) continue;
            dp[i] = min(dp[i], dp[i-digito]+1);
        }
    }

    cout << dp[n] << endl;
}