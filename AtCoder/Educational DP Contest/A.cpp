#include <bits/stdc++.h>
using namespace std;
using ll = long long;





int main(){
    int n;
    cin >> n;
    vector<int> altura(n);

    for(int i=0; i<n; i++){
        cin >> altura[i];
    }

    vector<int> dp(n);
    dp[n-1] = 0;
    dp[n-2] = abs(altura[n-1] - altura[n-2]);
    

    for(int i=n-3; i>=0; i--){
        dp[i] = min(dp[i+1] + abs(altura[i] - altura[i+1]), dp[i+2] + abs(altura[i] - altura[i+2]));
    }


    cout << dp[0] << endl;


}

