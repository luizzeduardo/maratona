#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    // circulo perfeito
    int n;
    cin >> n;
    vector<int> quant(n);
    for(int i=0; i<n; i++){
        cin >> quant[i];
    }

    // elas só andam no sentido horario
    int melhor = INT_MAX;
    for(int i=0; i<n; i++){
        int custo = 0;
        for(int j=1; j<n; j++){
            int pos = (i+j)%n;
            custo += quant[pos]*j;
        }
        if(custo < melhor){
            melhor = custo;
        }
    }

    cout << melhor << endl;
}