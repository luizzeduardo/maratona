#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll par = 0;
        ll lastpar = 0;
        ll impar = 0;
        vector<ll> a(n);
        for(ll i=0; i<n; i++){
            cin >> a[i];
            if(a[i]%2 == 1){
                impar++;
            }
            else{
                par++;
                lastpar = a[i];
            }
        }
        //a é estritamente maior sempre (a1 < a2 < ... an)

        bool impossivel = true;
        //se há mais de um num de mesma paridade o mod deles sempre será par, isso para os pares
        if(par>1){
            impossivel = false;
            ll aux = 0;
            for(ll i=0; i<n; i++){
                if(aux > 1){
                    break;
                }
                if(a[i]%2 == 0){
                    cout << a[i];
                    aux++;
                    if(aux == 2) break;
                    cout << " ";
                }
            }
            cout << endl;
        }
        // tem extamente um par nos nums
        // todos os impares menores q esse par podem talvez dividir ele
        else if(par == 1){
            for(ll i=0; a[i]<lastpar; i++){
                ll q = lastpar%a[i];
                if(q%2 == 0){
                    impossivel = false;
                    cout << a[i] << " " << lastpar << endl;
                    break;
                }
            }
            // n achou nenhum q diividisse o par
            for(ll i=0; i<n-1; i++){
                for(ll j=i+1; j<n; j++){
                    if(a[i]%2 == 1 && a[j]%2 == 1){
                        ll q = a[j]/a[i];
                        if(q%2 == 1){
                            impossivel = false;
                            cout << a[i] << " " << a[j] << endl;
                            break;
                        }
                    }
                }
                if(!impossivel){
                    break;
                }
            }
        }

        else{
            for(ll i=0; i<n-1; i++){
                for(ll j=i+1; j<n; j++){
                    ll q = a[j]%a[i];
                    if(q%2 == 0){
                        impossivel = false;
                        cout << a[i] << " " << a[j] << endl;
                        break;

                    }
                }
                if(!impossivel){
                    break;
                }
            }
        }
        if(impossivel){
            cout << -1 << endl;
        }
    }
}