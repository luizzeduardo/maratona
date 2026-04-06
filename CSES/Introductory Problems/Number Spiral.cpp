#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        ll val = 0;
        if(x >= y){
            //par
            if(x%2 == 0){
                val = x*x;
                val -= y-1;
            }
            //impar
            else{
                val = (x-1)*(x-1) + 1;
                val += y-1;
            }
        }
        else if(y > x){
            //par
            if(y%2 == 1){
                val = y*y;
                val -= x-1;
            }
            //impar
            else{
                val = (y-1)*(y-1) + 1;
                val += x-1;
            }
        }

        cout << val << endl;
    }
}