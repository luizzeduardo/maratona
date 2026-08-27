#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> dp(n+1, vector<int> (m+1, INT_MAX));
	
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i == j) dp[i][j] =0;
			else{
				for(int h=1; h<i; h++){
					dp[i][j] = min(dp[i][j], dp[h][j] + dp[i-h][j] +1);
				}
				for(int h=1; h<j; h++){
					dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j-h] + 1);
				}
			}
		}
	}
	
	cout << dp[n][m] << endl;
}