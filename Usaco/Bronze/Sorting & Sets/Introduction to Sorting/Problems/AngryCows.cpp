#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> fenos(n);
    for(int i=0; i<n; i++) cin >> fenos[i];

    sort(fenos.begin(), fenos.end());

    int total = 0;

    for(int i=0; i<n; i++){

        auto it = fenos.begin() + i;
        
        for(int j = 1; ; j++){
            auto nit = lower_bound(fenos.begin(), it, *it - j);
            if(nit == it) break;  
            it = nit;
        }
        auto base = it;

        
        it = fenos.begin() + i;
        for(int j = 1; ; j++){
            auto nit = upper_bound(it, fenos.end(), *it + j) -1;
            if(nit == it) break;  
            it = nit;
        }
        auto topo = it;


        total = max<int>(total, topo - base +1);
    }

    cout << total << endl;

}