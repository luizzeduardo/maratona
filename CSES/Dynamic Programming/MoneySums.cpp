#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> coins(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin >> coins[i];
        sum+= coins[i];
    }

    int k = 0;
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for(int coin: coins){
        for (int i = sum; i >= coin; i--){
            if(coin > i) continue;
            if(dp[i-coin] == true){ 
                if(dp[i] == false) k++;
                dp[i] = true;
                
            }
        }
    }

    cout << k << endl;
    for(int i=1; i<sum+1; i++){
        if(dp[i] == true){
            cout << i << " ";
        }
    }


}