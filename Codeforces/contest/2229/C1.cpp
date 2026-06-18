#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        vector<int> pos;
        int total = 0;
        int sinal = 1;
        for(int i=n-1; i>=0; i--){
            if(sinal * a[i] > 0){
                pos.push_back(i+1);
                total ++;
                sinal = -sinal;
            }
        }

        cout << total << endl;
        for(int i = 0; i < total; i++ ){
            cout << pos[i] << " ";
        }
        cout << endl;

        //minimizar as operações
    }
}