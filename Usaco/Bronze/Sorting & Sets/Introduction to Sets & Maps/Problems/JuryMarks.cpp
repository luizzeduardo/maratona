#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int k;
    cin >> k;
    int n ;
    cin >> n;



    vector<int> a(k);
    for(int i=0; i<k; i++) cin >> a[i];

    vector<int> prefix(k);
    prefix[0] = a[0];
    for(int i=1;i<k; i++){
        prefix[i] = prefix[i-1] + a[i];
    }

    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> b[i];


    ll total = 0;

    set<int> pos;
    
    for(int j=0; j<k; j++){
        int cand = b[0] - prefix[j];
        pos.insert(cand);
    }


    for(int cand: pos){
        set<ll> sums;
        for(int i=0;i<k; i++){
            sums.insert((ll)cand + prefix[i]);
        }
        bool pode = true;
        for(int i=0; i<n; i++){
            if(sums.count(b[i]) == 0){
                pode = false;
                break;
            } 
        }

        if(pode) total++;
    }

    cout << total << endl;
}