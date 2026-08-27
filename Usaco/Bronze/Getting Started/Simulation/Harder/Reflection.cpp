#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int u;
    cin >> u;
    vector<string> quadro(n);
    vector<vector<pair<int,int>>> quant(n/2, vector<pair<int, int>>(n/2, make_pair(0,0)));
    for(int i=0; i<n; i++){
        cin >> quadro[i];
    }

    vector <pair<int,int>> muda(u);
    for(int i=0; i<u; i++){
        cin >> muda[i].first;
        cin >> muda[i].second;
        muda[i].first--;
        muda[i].second--;
    }

    int menor = INT_MAX;
    // verificaçao
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            // comparar bit a bit nos 4 quadros
            if(quadro[i][j] == '.'){
                quant[i][j].first++;
            }
            else{
                quant[i][j].second++;
            }
            //q2
            if(quadro[i][n-1-j] == '.'){
                quant[i][j].first++;
            }
            else{
                quant[i][j].second++;
            }
            //q3
            if(quadro[n-1-i][j] == '.'){
                quant[i][j].first++;
            }
            else{
                quant[i][j].second++;
            }
            //q4
            if(quadro[n-1-i][n-1-j] == '.'){
                quant[i][j].first++;
            }
            else{
                quant[i][j].second++;
            }
        }
    }

    int custo = 0;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            custo += min(quant[i][j].first, quant[i][j].second);
        }
    }
    cout << custo << endl;


    for(int i = 0; i<u; i++){
        int x = muda[i].first;
        int y = muda[i].second;

        int antigo = min(quant[min(x,n-1-x)][min(y,n-1-y)].first, quant[min(x,n-1-x)][min(y,n-1-y)].second);

        // troca
        if(quadro[x][y] == '.'){
            quadro[x][y] = '#';
            quant[min(x,n-1-x)][min(y,n-1-y)].second++;
            quant[min(x,n-1-x)][min(y,n-1-y)].first--;
        }
        else{
            quadro[x][y] = '.';
            quant[min(x,n-1-x)][min(y,n-1-y)].first++;
            quant[min(x,n-1-x)][min(y,n-1-y)].second--;
        }
        int novo = min(quant[min(x,n-1-x)][min(y,n-1-y)].second, quant[min(x,n-1-x)][min(y,n-1-y)].first);
        custo -= antigo;
        custo += novo;
        cout << custo << endl;

    }

}