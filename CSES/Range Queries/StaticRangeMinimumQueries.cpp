#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> st(25, vector<int>(n));
    for(int i=0; i<n; i++) st[0][i] = nums[i];
    
    for(int i=1; i<25; i++){
        for(int j=0; j + (1 << i)<=n; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;      // index 0  
        int k = __lg(b - a + 1);              
        int resp = min(st[k][a], st[k][b - (1 << k) + 1]);

        cout << resp << endl;

    }    
}