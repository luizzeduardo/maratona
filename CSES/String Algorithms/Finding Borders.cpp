#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int B = 26;
const int A = 999999997;

int add(int a, int b) {
    a += b;
    if (a >= A) a -= A;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += A;
    return a;
}

int mult(int a, int b) {
    return (ll)a * b % A;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        prefix[i + 1] = add(mult(prefix[i], B), c);
    }



    vector<int> bordas;
    int powB = 1;

    for (int i = 1; i < n; i++) {
        powB = mult(powB, B);          
        int hash_prefix = prefix[i];
        int hash_sufix = sub(prefix[n], mult(prefix[n - i], powB));

        
        if (hash_prefix == hash_sufix) bordas.push_back(i);
    }

    for (int x : bordas) cout << x << " ";
    cout << endl;
}