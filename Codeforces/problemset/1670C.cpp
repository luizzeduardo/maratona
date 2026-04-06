#include <bits/stdc++.h>
using namespace std;

int main(){
    int div = 1000000007;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        vector<int> d(n,0);
        for(int i=0; i<n; i++){
            cin >> d[i];
        }

        vector<int> posA(n + 1), posB(n + 1);
        for (int i = 0; i < n; i++) {
            posA[a[i]] = i;
            posB[b[i]] = i;
        }

        vector<bool> vis(n + 1, false);
        long long ans = 1;

        //basta ver quantos componentes independentes são

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            

            int cur = i;
            bool fixed = false;
            int len = 0;
            
            while (!vis[cur]) {
                vis[cur] = true;
                len++;
                
                int idxA = posA[cur];
                int idxB = posB[cur];
                
                // Se != 0, então fixo
                if (d[idxA] != 0) fixed = true;
                if (d[idxB] != 0) fixed = true;

                if (!vis[b[idxA]]) {
                    cur = b[idxA];
                } else {
                    cur = a[idxB];
                }
            }
            
            if (!fixed && len > 1) {
                ans = (ans * 2) % div;
            }
        }

        cout << ans << endl;
    }
}