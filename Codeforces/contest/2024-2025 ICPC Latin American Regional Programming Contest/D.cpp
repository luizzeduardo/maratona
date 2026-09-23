#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    set<int> s;
    for (int i=0; i<n; i++) if (a[i]) s.insert(a[i]);

    vector<int> pos(n+1, -1);
    for (int i=0; i<n; i++) if (a[i]) pos[a[i]] = i;

    bool ok = 1;
    int l = 0, r = n-1;
    for (int x=1; ok && x<=n; x++) {
        if (pos[x] == -1) {
            // precisa remover um zero
            auto ub = s.upper_bound(x);
            if (ub == s.end()) {
                if (!a[l]) { a[l] = x; l++; }
                else if (!a[r]) { a[r] = x; r--; }
                else ok = 0;
            } else {
                int y = *ub;
                int rem_l = pos[y] - l,
                    rem_r = r - pos[y];

                if (rem_l < rem_r) {
                    if (!a[l]) { a[l] = x; l++; }
                    else if (!a[r]) { a[r] = x; r--; }
                    else ok = 0;
                } else {
                    if (!a[r]) { a[r] = x; r--; }
                    else if (!a[l]) { a[l] = x; l++; }
                    else ok = 0;
                }
            }

        } else {
            // precisa remover o número em uma das pontas
            if (a[l] == x) l++;
            else if (a[r] == x) r--;
            else ok = 0;
        }
    }

    if (!ok) {
        cout << "*\n";
    } else {
        for (int i=0; i<n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
}