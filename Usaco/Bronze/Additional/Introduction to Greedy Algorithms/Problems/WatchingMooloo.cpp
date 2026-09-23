#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // d+K para comprar durante d dias

    // a melhor opção é ver se vc continua a assinatura do dia anterior ou cria uma nova
    // min(k+a[i]-a[i-1]+1, intervalo anterior + k+1)

    ll resp = k+1;
    for(int i=1; i<n; i++){
        resp += min(a[i] - a[i-1], k + 1);

    }

    cout << resp << endl;
}