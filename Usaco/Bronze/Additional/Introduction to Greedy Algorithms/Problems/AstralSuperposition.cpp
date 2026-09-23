#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int A, B;
        cin >> A >> B;
        // A -> para esquerda
        // B -> desce
        vector<string> espaco(n);
        for(int i=0; i<n; i++){
            cin >> espaco[i];
        }
        // é sempre ótimo ver os G mais a cima e ver se os de baixo podem ser formados por eles
        // se existem B ou G que podem ser formados é um a menos a contar em ambos os casos
        vector<vector<int>> valor(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(espaco[i][j] == 'W') valor[i][j] = 0;
                if(espaco[i][j] == 'G') valor[i][j] = 1;
                if(espaco[i][j] == 'B') valor[i][j] = 2;
            }
        }
        int total = 0;
        bool pode = true;
        for(int i=0; i<n; i++){
            if(!pode) break;
            for(int j=0; j<n; j++){
                if(!pode) break;
                if(valor[i][j]) total++;


                if(valor[i][j] == 2){
                    if((i-B) >= 0 && (j-A) >= 0){
                        if(valor[i-B][j-A]==0){ pode= false;}
                    }
                    else pode= false;
                }


                if(valor[i][j] >= 1){
                    if((i+B)< n && (j+A)<n){
                        if(valor[i+B][j+A]==1){
                            if((i+2*B)< n && (j+2*A)< n){
                                if(valor[i+2*B][j+2*A] < 2) valor[i+B][j+A]--;
                            }
                            else valor[i+B][j+A]--;
                        }
                    }
                }
            }
        }
        if(pode) cout << total << endl;
        else cout << -1 << endl;
    }
}