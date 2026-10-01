#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void inverte(vector<int> &seq, int a, int b){
    int diff = b-a;
    diff /= 2;
    for(int i=a; i<=a+diff; i++){
        int aux = seq[i];   
        seq[i] = seq[b-(i-a)];
        seq[b-(i-a)] = aux;
    }
}

int main(){

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n, k;
    cin >> n;
    cin >> k;

    // não da pra percorrer todos os valores sempre

    // 1 2 3 4 5 6 7

    // 1 rodada
    // 1 5 4 3 2 6 7
    // 1 5 7 6 2 3 4

    // 2 rodada
    // 1 2 6 7 5 3 4
    // 1 2 4 3 5 7 6

    // 3 rodada
    // 1 5 3 4 2 7 6
    // 1 5 6 7 2 4 3

    // 4 rodada
    // 1 2 7 6 5 4 3
    // 1 2 3 4 5 6 7
    int a1, a2;
    cin >> a1 >> a2;
    a1--; a2--;
    int b1, b2;
    cin >> b1 >> b2;
    b1--; b2--;

    vector<vector<int>> estados;
    vector<int> seq(n);
    for(int i=0; i<n; i++) seq[i] = i+1;
   

    do{
        estados.push_back(seq);
        inverte(seq, a1, a2);
        inverte(seq, b1, b2);

    }while(estados[0] != seq);

    int pos = k%estados.size();

    for(int i=0; i<n; i++) cout << estados[pos][i] << endl;

    
}