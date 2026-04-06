#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool pode_fazer(int k, int a, int b) {
    // Testa se podemos fazer k camadas começando com branco
    auto testa = [&](int inicio) {
        ll branco = a, escuro = b;
        for (int i = 0; i < k; i++) {
            ll tam = 1LL << i;
            if ((inicio + i) % 2 == 0) {
                if (branco < tam) return false;
                branco -= tam;
            } else {
                if (escuro < tam) return false;
                escuro -= tam;
            }
        }
        return true;
    };
    
    return testa(0) || testa(1);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int left = 0, right = 20; // 2^20 > 10^6
        int ans = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (pode_fazer(mid, a, b)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}