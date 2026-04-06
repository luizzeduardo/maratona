#include <bits/stdc++.h>
using namespace std;

int main() {


    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> mask(n, 0);
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                mask[j] |= 1 << (s[j] - 'a');
            }
        }

        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d != n / d) divisors.push_back(n / d);
            }
        }
        sort(divisors.begin(), divisors.end());

        int best_d = n;
        vector<int> group_mask;

        for (int d : divisors) {
            vector<int> gmask(d, (1 << 26) - 1);
            bool valid = true;

            for (int g = 0; g < d; g++) {
                for (int i = g; i < n; i += d) {
                    gmask[g] &= mask[i];
                    if (gmask[g] == 0) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (valid) {
                best_d = d;
                group_mask = move(gmask);
                break;
            }
        }

        string ans(n, 'a');
        for (int i = 0; i < n; i++) {
            int g = i % best_d;
            int m = group_mask[g];
            int first_letter = __builtin_ctz(m);
            ans[i] = 'a' + first_letter;
        }
        cout << ans << '\n';
    }

    return 0;
}