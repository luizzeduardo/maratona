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

    vector<ll> prefix(n+1, 0);
    map<ll, ll> resp;

    for(int i=1; i<=n; i++){
        prefix[i] += (prefix[i-1]+a[i-1]);
    }

    for(int i=0; i<=n; i++){
        prefix[i] = ((prefix[i] % n) + n) % n;
    }
    
    for(int i=0; i<=n; i++){
        resp[prefix[i]]++;
    }

    // n*(n-1)/2
    ll total = 0;
    for(auto [x, y]: resp){
        total+= y*(y-1)/2;
    }

    cout << total << endl;
}