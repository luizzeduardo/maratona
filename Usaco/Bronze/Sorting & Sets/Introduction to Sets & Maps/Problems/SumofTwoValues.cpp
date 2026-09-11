#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ll n;
    cin >> n;
    int x;
    cin >> x;
    map<ll, ll> resp;
 
    ll a = -1;
    ll b = -1;
    for(int i=0; i<n; i++){
        ll aux;
        cin >> aux;
        // cout << aux << " " << resp[aux] << " " << resp[x-aux] << endl;
 
        
        if(resp[x-aux]>0){
            b = resp[x - aux];
            a = i+1;
        }
        resp[aux] = i+1;
    }
 
    if(a>=0 && b>=0){
        cout << b << " " << a << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}