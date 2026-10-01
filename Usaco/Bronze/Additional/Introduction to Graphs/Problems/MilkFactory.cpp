#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> saida(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        saida[a]++;
    }

    //  guardar os caminhos n-1 caminhos, como é tudo conexo
    //  no melhor caso, apenas um no não tem caminhos, q seria o que todos chegam
    // 1 -> 2 -> 3
    // 1 1 0
    // caso ruim
    // 1 -> 2 -> 3 <- 4 -> 5
    // 1 1 0 2 0
    //só serve quando tiver apenas um zero
    int resp = -1, semSaida = 0;
    for (int i = 1; i <= n; i++){
        if (saida[i] == 0) { semSaida++; resp = i; }
    }

    if(semSaida == 1){
        cout << resp << endl;
    }
    else{
        cout << -1 << endl;
    }
    
}