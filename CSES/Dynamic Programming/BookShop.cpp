#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int lim;
    cin >> lim;

    vector<pair<int, int>> livro(n);
    for(int i=0; i<n; i++){
        cin >> livro[i].first;
    }

    for(int i=0; i<n; i++){
        cin >> livro[i].second;
    }

    vector<vector<int>> dp(n+1, vector<int> (lim+1, 0));

    for(int i=1; i<=n; i++){
        int custo  = livro[i-1].first;  
        int pags = livro[i-1].second;
        for(int j=0; j<=lim; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= custo){
                dp[i][j] = max(dp[i][j], dp[i-1][j-custo] + pags);
            }
        }
    }


    cout << dp[n][lim] << endl;

}