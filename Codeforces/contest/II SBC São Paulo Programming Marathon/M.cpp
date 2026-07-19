#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> b(n+2);
    for(ll i=0;i<n+2; i++){
        cin >> b[i];
    }

    ll s = -1; // maior elem
    for(ll i=0; i< b.size(); i++){
        if(s < b[i]){
            s = b[i];
        } 
    }
    b.erase(find(b.begin(), b.end(), s));


    ll total = 0;

    ll m;
    for(ll i=0; i< b.size(); i++){
        total+= b[i];
    }

    m = total - s*(n-1);
    b.erase(find(b.begin(), b.end(), m));





    vector<ll> final(n);
    for(ll i=0; i<n; i++){
        final[i] = s - b[i];
    }

    sort(final.begin(), final.end());

    cout << s << " " << m << endl;

    for(ll i=0; i<n; i++){
        cout<< final[i] << " ";
    }
    cout << endl;






}