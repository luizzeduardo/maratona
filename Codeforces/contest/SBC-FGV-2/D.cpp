#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, Q;
    cin >> N >> Q;
 
    string S;
    cin >> S;
 
    char inicial = S[0];
    int Af = 0;
    while (Af < N && S[Af] == inicial ) {
        Af++;
    }
 
    string T;
    while (Q--) {
        cin >> T;
        int M = (int)T.size();
        int Bf = 0;
        while (Bf < M && T[Bf] == inicial){
            Bf++;
        } 
        cout << (N + M - min(Af, Bf)) << '\n';
    }
    return 0;
}