#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;

        vector<vector<ll>> area(1001, vector<ll>(1001, 0));


        for(ll i=0; i<n; i++){
            int hi, wi;
            cin >> hi;
            cin >> wi;
            area[hi][wi] += (ll)hi * wi;
        }

        vector<vector<ll>> prefix(1001, vector<ll>(1001, 0));

        for(int i=1; i<1001 ; i++){
            for(int j=1; j<1001; j++){
                prefix[i][j] = area[i][j] + prefix[i-1][j]  + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }





        while(q--){
            ll hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            int h_min = hs+1;
            int h_max = hb-1;
            int w_min = ws+1;
            int w_max = wb-1;

            if(h_min > h_max || w_min > w_max){
                cout << 0 << endl;
            }
            else{
                ll resposta = prefix[h_max][w_max] - prefix[h_min-1][w_max] - prefix[h_max][w_min-1] + prefix[h_min-1][w_min-1];
                cout << resposta << endl;
            }
        }

        //prefix??
        //amazenar em uma matriz
        // prefix[i][j] - prefix[i-1][j] - prefix[i][j-1] + prefix[i-1][j-1]
        
    }
}