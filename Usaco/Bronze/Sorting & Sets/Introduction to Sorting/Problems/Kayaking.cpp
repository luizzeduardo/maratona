#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> pesos(2*n);
    for(int i=0; i<n*2; i++) cin >> pesos[i];

    sort(pesos.begin(), pesos.end());
    int menor = INT_MAX;


    for(int i=0; i<n*2; i++){
        for(int j=i+1; j<n*2; j++){
            int local = 0;
            for(int k=0; k<n*2; k++){
                if(k == i || k == j) continue;

                int prox = k+1;
                while(prox == i || prox == j) prox++;
                local += pesos[prox] - pesos[k];
                k = prox;
            }

            menor = min(menor, local);
        }
    }

    cout << menor << endl;
}