#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i=0; i<m; i++){
            cin >> a[i];    
        } 
        //questão de ver se é um intervalo padrão
        // se não for é 1
        bool padrao = true;
        if(a.size() > 1){
            int ant = a[0];
            for(int i=1; i<m; i++){
                if(ant+1 != a[i]){
                    padrao = false;
                    break;
                }
                ant = a[i];
            }
        }

        if(!padrao){
            cout << 1 << endl;
        }
        else{
            int last = a[m-1];
            int quant = n+1 - last;
            cout << quant << endl;
        }
    }
    
}