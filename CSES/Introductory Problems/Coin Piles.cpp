#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;

        

        // se a soma de A e B é um multiplo de 3 e o menor*2 é igual ou maior que o maior, então é válido


        ll menor = min(a, b);
        ll maior = max(a, b);


        if((a+b)%3 == 0 && 2*menor >= maior){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}