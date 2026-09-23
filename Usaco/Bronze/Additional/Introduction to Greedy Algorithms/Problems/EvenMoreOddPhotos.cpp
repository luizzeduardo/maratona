#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int pares = 0;
    int impares = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2 == 0)pares++;
        else impares++;
    }

    if(pares == impares){ cout << pares*2 << endl; return 0;}
    if(pares > impares) { cout << impares*2 + 1 << endl; return 0;}

    int total = 0;

    bool paridade = true; // true -> par, false impar
    while(pares>0 || impares>0){
        if(paridade){
            if(pares>0){
                total++;
                pares--;
            }
            else if(impares >= 2){
                total++;
                impares -= 2;
            }
            else {
                if(impares == 1){
                    total--;
                    break;
                }
            }

            paridade = false;
        }
        else{
            if(impares>0){
                total++;
                impares--;
            }
            paridade = true;
        }
    }


    cout << total << endl;

}