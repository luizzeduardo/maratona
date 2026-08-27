#include <bits/stdc++.h>
using namespace std;
using  ll = long long;

constexpr int mod = 1000000007;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	vector<int> b(m+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=m; i++){
		cin >> b[i];
	}
	
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] +1;
			}
			else{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	
	cout << dp[n][m] << endl;


    vector<int> resposta;
    int i = n; int j = m;
    while(i > 0 && j> 0){
        if(a[i] == b[j]){
            resposta.push_back(a[i]);
            i--; j--;

        }
        else if(dp[i][j-1] <= dp[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }
    
	reverse(resposta.begin(), resposta.end());

    for(int resp : resposta) cout << resp << " ";
    cout << endl;
}