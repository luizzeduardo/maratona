#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        if (n == 1) {
            cout << p[0] << endl;
            continue;
        }
        
        int l = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] != n - i) {
                l = i;
                break;
            }
        }
        
        if (l != -1) {
            int target = n - l;
            int r = -1;
            for (int i = l; i < n; i++) {
                if (p[i] == target) {
                    r = i;
                    break;
                }
            }
            reverse(p.begin() + l, p.begin() + r + 1);
        }
        
        // Imprimir resultado
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}