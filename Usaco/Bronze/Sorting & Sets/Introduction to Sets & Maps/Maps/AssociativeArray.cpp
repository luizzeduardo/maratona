#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int t;
    cin >> t;
    map<ll, ll> resp;
    while(t--){

        int op;
        cin >> op;

        if(op == 0){
            ll i;
            cin >> i;
            ll val;
            cin >> val;
            resp[i] = val;
        }
        if(op == 1){
            ll i;
            cin >> i;
            cout << resp[i] << endl;
        }
    }
}