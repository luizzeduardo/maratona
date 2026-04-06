#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll num){
    if(num <  0){
        num = -1*num;
    }
    return num;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll p, q;
        cin >> p >> q;


        bool continua = true;
        ll i = 1;
        while(continua){
            if(2*i <= p || 3*i <= q){
                if(p - 2*i == q - 3*i){
                    cout << "Bob" << endl;
                    continua = false;
                }
                else{
                    ll dif = (p - 2*i) - (q - 3*i);
                    dif = mod(dif);
                    i += dif;
                }
            }
            else{
                cout << "Alice" << endl;
                continua = false;
            }
        }
        
    }
}