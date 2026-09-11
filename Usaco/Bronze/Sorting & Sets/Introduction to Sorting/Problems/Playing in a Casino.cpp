#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cartas (n, vector<int> (m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> cartas[i][j];
            }
        }

        ll resp = 0;
        vector<int> col(n);
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                col[i] = cartas[i][j];
            }
            sort(col.begin(), col.end());

            for(int i=0; i<n; i++){
                ll peso =  n-1 - i;
                resp += peso * col[i];
                resp -= (ll)i*col[i];
            }



        }

        cout << abs(resp) << endl;


    }
}