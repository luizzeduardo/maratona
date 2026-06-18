#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int dados[3][7] = {0}; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int x; cin >> x;
            dados[i][x]++;
        }
    }

    int favoraveis = 0;
    vector<int> valores = {4, 5, 6};
    
    do {
        favoraveis += dados[0][valores[0]] * dados[1][valores[1]] * dados[2][valores[2]];
    } while (next_permutation(valores.begin(), valores.end()));

    double prob = favoraveis / 216.0;
    cout << fixed << setprecision(10) << prob << endl;
}