#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;
    
    // si e ti  intervalo de tempo que a vaca precisa ser ordenhada
    // bi a quantidade de baldes necessários para ordenhá-la

    vector<int> total_baldes(1000, 0);

    int maior = 0;
    for(int i=0; i<n; i++){
        int inicio, fim, baldes;
        cin >> inicio >> fim >> baldes;
        inicio--;
        fim--;

        for(int i=inicio; i<=fim; i++){
            total_baldes[i]+=baldes;
            if(maior < total_baldes[i]){
                maior = total_baldes[i];
            }
        }
    }

    cout << maior << endl;

    


}