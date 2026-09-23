#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];


    set<ll> foi;
    map<ll, pair<ll, ll>> pos;
    for(ll i=0; i<n; i++){
        if(foi.count(a[i]) == 0){
            foi.insert(a[i]);
            pos[a[i]] = make_pair(i, i);
        }

        else{
            pos[a[i]].second = i;
        }
    }

    vector<pair<ll, ll>> iv;
    for(auto[num, poses] : pos) iv.push_back(poses);
    sort(iv.begin(), iv.end());

    vector<pair<ll, ll>> blocos;
    for(auto[l, r] : iv){
        if(!blocos.empty() && l <= blocos.back().second)
            blocos.back().second = max(blocos.back().second, r);
        else
            blocos.push_back({l, r});
    }

    ll total = 0;

    for(auto[l, r] : blocos){
        ll maior = 0;
        map<ll, ll> quant;
        for(ll i=l; i<=r; i++){
            quant[a[i]]++;
            if(quant[a[i]] > maior) maior = quant[a[i]];
        }

         total += r - l + 1 - maior;
    }


    cout << total << endl;
}