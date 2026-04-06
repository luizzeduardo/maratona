#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll min = 0;

    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(i==0){
            min = a[0];
        }
        else if(a[i] < min){
            min = a[i];
        }
    }




    ll total = 0;

    for(int i = 0; i<n; i++){
        ll dif = a[i] - min;

        if(dif%k != 0){
            cout << -1 << endl;
            return 0;
        }

        total += dif/k;
    }
    cout << total << endl;
    return 0;
}