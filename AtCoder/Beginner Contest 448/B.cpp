#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    //apenas uma pimenta por prato sendo Ai < N

    vector<int> C(m + 1); 
    for (int j = 1; j <= m; ++j) {
        cin >> C[j];
    }

    vector<int> demanda(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int A, B;
        cin >> A >> B;
        demanda[A] += B;
    }

    int resposta = 0;
    for (int j = 1; j <= m; ++j) {
        resposta += min(C[j], demanda[j]);
    }

    cout << resposta << endl;
}