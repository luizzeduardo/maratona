#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector<int> capacidade(3);
    vector<int> quant(3);
    for(int i=0; i<3; i++){
        cin >> capacidade[i] >> quant[i];
    }

    int i=0;
    while(i<100){
        int sai = i%3;
        int entra = (sai+1)%3;
        // o sai enche o entra
        if(quant[sai] > capacidade[entra]-quant[entra]){
            quant[sai] -= capacidade[entra]-quant[entra];
            quant[entra] = capacidade[entra];
        }
        // o sai n enche o entra
        else{
            quant[entra] += quant[sai];
            quant[sai] = 0;
        }
        i++;
    }

    cout << quant[0] << endl;
    cout << quant[1] << endl;
    cout << quant[2] << endl;

}