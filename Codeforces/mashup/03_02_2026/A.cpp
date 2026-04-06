#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;


    while(t--){
        ll n, a, b;

        cin >> n >> a >> b;

        if (b <= a) {
            cout << n * a << "\n";
            continue;
        }

        ll kmax = min(n, b);
        
        ll k = min(kmax, b - a);

        if (k < 0){
            k = 0;
        } 
        

        ll sum_promo = k * (2 * b - k + 1) / 2;
        
        ll sum_normal = (n - k) * a;
        
        ll profit = sum_promo + sum_normal;
        
        cout << profit << "\n";
    }
    
    return 0;
}

