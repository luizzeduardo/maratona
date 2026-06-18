#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;
//marcar as reps
// entre os intervalos das repeticções pegar as possibilidade com numeros triangulares
int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    long long ans = 0;
    int segment_len = 1;  
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            ans += (long long)segment_len * (segment_len + 1) / 2;
            ans %= mod;
            segment_len = 1;  
        } else {
            segment_len++;
        }
    }
    
    ans += (long long)segment_len * (segment_len + 1) / 2;
    ans %= mod;

    cout << ans << endl;
    
    return 0;
}