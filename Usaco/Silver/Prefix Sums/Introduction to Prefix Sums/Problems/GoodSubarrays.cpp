#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> prefix(n+1, 0);
        for(int i=1; i<=n; i++){
            prefix[i] += prefix[i-1]+ ll(s[i-1]-'0');
        }

        map<ll, ll> quant;
        for(int i=0; i<=n; i++){
            quant[prefix[i] - i]++;
        }

        ll total = 0;
        for(auto[x, y] : quant){
            total += y*(y-1)/2;
        }

        cout << total << endl;
    }
}