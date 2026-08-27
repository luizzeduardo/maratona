#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    string n;
    cin >> n;
    string m;
    cin >> m;

    int x = n.size();
    int y = m.size();

    int maior = max(x, y);

    vector<vector <int>> dp(x+1, vector<int> (y+1, 0));
    for(int i=0; i<=x; i++) dp[i][0] = i;
    for(int i=0; i<=y; i++) dp[0][i] = i;
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(n[i-1] == m[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            } 
        }
    }

    cout << dp[x][y];
}