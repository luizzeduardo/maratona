#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const unsigned long long B = 131; // base

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;

    unordered_set<unsigned long long> dict;

    auto compute_hash = [&](const string &w) -> unsigned long long {
        unsigned long long h = 0;
        for (char c : w) {
            h = h * B + (c - 'a');   // overflow natural = mod 2^64
        }
        return h;
    };

    for (int i = 0; i < k; i++) {
        string w;
        cin >> w;
        dict.insert(compute_hash(w));
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;
        unsigned long long h = 0;
        for (int j = i; j < n; j++) {
            h = h * B + (s[j] - 'a');   // hash de s[i..j]
            if (dict.count(h)) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}