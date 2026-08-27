#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){
    int n;
    cin >> n;

    string s; // ex: oxoxoxoxox
    // o -> sentado
    // x -> esta vazio


    // xx na ponta e xxx no meio

    cin >> s;

    int aux = 0;

    for(int i=0; i<n; i++){
        
        if(s[i] == 'x'){
            //borda
            if(i == 0 && s[i+1] == 'x'){
                aux++;
            }
            else if(i == n-1 && s[i-1] == 'x'){
                aux++;
            }

            else if(i != 0 && i != n-1){
                if(s[i+1] == 'x' && s[i-1] == 'x'){
                    aux++;
                }
            }
        }
    }

    if(n ==1 && s[0] == 'x'){
        aux++;
    }

    cout << aux << endl;
}