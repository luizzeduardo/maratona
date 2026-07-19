#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll q;
    cin >> q;

    vector<ll> custo(n);
    vector<ll> tocando(n);
    for(int i=0; i<n; i++){
        cin >> custo[i];
        cin >> tocando[i];
    }



    // ou esta num q não odeia, ou esta num que odeia
    // se odeia pular todos que sejam do mesmo estilo que o odiado
    vector<ll> proximoDiferente(n, n);
    for(int i=n-2; i>=0; i--){
        if(tocando[i] == tocando[i+1]){
            proximoDiferente[i] = proximoDiferente[i+1];
        }
        else{
            proximoDiferente[i] = i+1;
        }
    }



    for(int i=0; i<q; i++){
        ll limite;
        ll odeia;

        cin >> limite >> odeia;

        ll inicio = lower_bound(custo.begin(), custo.end(), limite, greater<ll>()) - custo.begin();

        ll ans;
        if(inicio==n){
            ans = -1;
        }
        else if(tocando[inicio] != odeia){
            ans = inicio + 1;
        }
        else{
            ll proximo = proximoDiferente[inicio];
            if(proximo < n){
                ans = proximo+1;
            }
            else{
                ans= -1;
            }
        }

        cout << ans << endl;
    }
}