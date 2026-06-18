#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }  

        vector<ll> faca(n);

        ll altura = a[0];    
        ll resto = 0;
        
        for(ll i=0; i<n; i++){
            if(a[i] > altura){
                resto += a[i] - altura; 
            } 
            if(a[i] < altura){
                ll falta = altura - a[i];
                if(falta <= resto){
                    resto -= falta;
                }
                else{
                    falta -= resto;
                    resto = 0;
                    ll faltaNivel = (falta + i) / (i + 1);
                    altura -= faltaNivel;
                    resto += faltaNivel*(i+1) - falta;
                }
            }
            faca[i] = altura;
        }
        for(ll i=0; i<n; i++){
            cout << faca[i] << " ";
        }
        cout << endl;
    }
}