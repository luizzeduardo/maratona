#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // só pode ter no maximo n^2 - n de um num para q possa ser reajanjado
        vector<int> quant(n * n + 1, 0);
        bool pode = true;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int idx;
                cin >> idx;
                quant[idx]++;
                if(quant[idx] > n*n - n){
                    pode = false;
                }
            }
        }
        if(pode){ 
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}