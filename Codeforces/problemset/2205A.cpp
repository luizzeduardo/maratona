#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // se o indice é igual ao maior elemento
        // tamanho da permutação r é m
        // minimizar o num de ugly, sempre teremos pelo menos uma, o maior elemento
        // idealmente sempre o maior na primeira posiçaõ

        vector<int> r(n+1, 0);
        int maior = 0;
        for(int i=0; i<n; i++){
            cin >> r[i];
            if(r[i] > r[maior]){
                maior = i;
            }
        }

        int aux = r[0];
        r[0] = r[maior];
        r[maior] = aux;

        for(int i=0; i<n; i++){
            cout << r[i] << " ";
        }
        cout << endl;

    }
}