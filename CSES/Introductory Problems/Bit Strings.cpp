#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

ll bitpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll res = bitpow(a, b/2);
    if(b%2){
        return (res * res * a)%MOD;
    }
    else{
        return (res * res)%MOD;
    }
}

int main(){
    ll n;
    cin >> n;
    // podemos usar a exponenciação binária
    ll num = bitpow(2,n);

    cout << num << endl;
}