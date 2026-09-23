#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> matriz(n);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        matriz[i] = s;
    }

    // como só podemos fazer retangulos a partir do ponto (0,0)
    // a melhor estratégia e começar tentando resolver os pontos mais distantes primeiro
    // e ir voltando de tras pra frente

    
    int quant = 0;
    vector<vector<int>> invertido (n, vector<int>(n, 0));

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){

            // tem q trocar
            if(matriz[i][j] == '1' && invertido[i][j] == 0){
                quant++;
                for(int x = 0; x<=i; x++){
                    for(int y = 0; y<=j; y++){
                        invertido[x][y]++;
                        invertido[x][y] %= 2;
                    }
                }
            }
            else if(matriz[i][j] == '0' && invertido[i][j] == 1){
                quant++;
                for(int x = 0; x<=i; x++){
                    for(int y = 0; y<=j; y++){
                        invertido[x][y]++;
                        invertido[x][y] %= 2;
                    }
                }
            }
        }
    }

    cout << quant << endl;
    

}