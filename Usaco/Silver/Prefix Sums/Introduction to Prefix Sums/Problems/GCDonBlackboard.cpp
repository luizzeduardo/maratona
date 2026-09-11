#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<ll> prefix(n, 0);
    prefix[0] = a[0];
    for(int i=1; i<n; i++){
        prefix[i] = gcd(prefix[i-1], a[i]);
    }

    vector<ll> sufix(n+1, 0);
    sufix[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        sufix[i] = gcd(sufix[i+1], a[i]);
    }

    ll maior = 0;
    for(int i=0; i<n; i++){
        ll div;
        if(i==0) div = sufix[i+1];
        else if(i==n-1) div = prefix[i-1];
        else div = gcd(prefix[i-1], sufix[i+1]);
        if(maior < div) maior = div;
    }

    cout << maior << endl;

}