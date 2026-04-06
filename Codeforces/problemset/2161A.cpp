#include <bits/stdc++.h>
using namespace std;

int main(){

    //existem n rounds de div1 e div2
    // round unrated n aumenta rating r
    // d o quanto pode mudar no maximo

    int t;
    cin >> t;
    while(t--){
        int r, x, d, n;
        cin >> r >> x >> d >> n;
        vector<char> div(n);
        for(int i=0; i<n; i++){
            cin >> div[i];
        }

        int dif = r-d;
        if(dif<0){
            dif = -1*dif;
        }
        int part = 0;
        for(int i=0; i<n; i++){
            if(div[i] == '2' && r<x){
                part++;
            }
            if(div[i] == '1'){
                if(r>=x){
                    r-=d;
                }
                part++;
            }
        }

        cout << part << endl;
    }
}