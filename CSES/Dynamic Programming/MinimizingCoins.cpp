#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int alvo;
    cin >> alvo;

    vector<int> moedas(n);
    vector<int> dp(alvo+1, INT_MAX);

    for(int i=0; i<n; i++){
        cin >> moedas[i];
    }
    dp[0] = 0;

    for(int moeda: moedas){
        for(int i=1; i<alvo+1; i++){
            if(i-moeda<0) continue;
            if(dp[i-moeda] == INT_MAX) continue;
            dp[i] = min(dp[i], dp[i-moeda]+1);
        }
    }


    if(dp[alvo] == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << dp[alvo] << endl;
    }

}