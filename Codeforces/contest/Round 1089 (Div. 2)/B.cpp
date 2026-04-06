
        



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        // passaria apenas um O(n logn)

        // tenho uma seq ideal para macar o maximo de cadeiras
        // quero sentar no maximo de cadairas
        // isso pode ser no maximo n-1 cadeiras (ideal)
        // no pior dos casos 2 cadeiras marcadas

        // basta ver o quanto q conseguiriamos da cadeira i até a p[i]

        
        vector<int> diff(n + 5, 0); // diferenças para m
        
        for (int i = 1; i <= n; ++i) {
            int pi = p[i-1];
            if (pi <= i) {
                diff[i+1] += 1;
                diff[n+2] -= 1;
            } else {
                diff[i+1] += 1;
                if (pi + 1 <= n+1) diff[pi+1] -= 1;
                else diff[n+2] -= 1;
            }
        }
        
        int resposta = 0, cur = 0;
        for (int m = 1; m <= n+1; ++m) {
            cur += diff[m];
            resposta = max(resposta, cur);
        }

        cout << resposta << endl;
        
    }
    
    return 0;
}