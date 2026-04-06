#include <bits/stdc++.h>
using namespace std;

//operações

//Trocar os elementos de a[i] pelo a[i+1]
//Trocar os elementos de a[i] pelo b[i]

//dá pra mudar qualquer num para qualquer lugar

//objetivo -> achar a maior soma possivel dos intervalos a[l] até a[r] 

//basicamente achar os k maiores nums das listas a e b, sendo k = r-l.
//



int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
            if(b[i] > a[i]){
                a[i] = b[i];
            }
        }
        //NÃO É UMA TROCA DE POSIÇÃO, É UMA SUBSTITUIÇÃO DUPLICADA, SÓ O SUBSTITUIDO MUDA
    

        for(int i=n-2; i>=0; i--){
            if(a[i] < a[i+1]){
                a[i] = a[i+1];
            }
        }

        vector<int> prefix(n);
        prefix[0] = a[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + a[i];
        }


        while(q--){
            int l, m;
            cin >> l >> m;
            l--; m--;
            int resposta = prefix[m] - prefix[l] + a[l];
            cout << resposta << " ";
        }
        cout << endl;
    }
    return 0;
}