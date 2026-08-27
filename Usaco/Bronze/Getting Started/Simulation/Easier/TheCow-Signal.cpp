#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);


    int m, n, k;
    cin >> m >> n >> k;

    vector<string> texto(m);
    for(int i=0; i<m; i++){
        cin >> texto[i];
    }

    for(int i=0; i<m; i++){
        for(int x=0; x<k; x++){
            for(int j=0; j<n; j++){
                for(int x=0; x<k; x++) cout << texto[i][j];
            }
            cout << endl;
        }
    }
}