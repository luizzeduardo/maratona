#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        // n é o tam de b (removido)
        // k a quant de removidos
        cin >> n >> k;
 
        vector<int> b(n);
        int total = 1;
        for(int i=0; i<n; i++){
            cin >> b[i];
            total *= b[i];
        }
        // 7⋅17⋅17 = 2023
        // se o produto da seq n dividir 2023 é impossivel
        bool possivel = true;
        int falta = 2023;
        
        for(int elem : b){
            if(falta%elem != 0){
                possivel = false;
                break;
            }
            else{
                falta /= elem;
            }
        }
 
        if(possivel){
            cout << "YES" << endl;
            cout << falta << " ";
            for(int i=1; i<k; i++){
                cout << "1" << " ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
 
 
 
    }
}