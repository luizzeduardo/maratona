#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    else{
        return(gcd(b, a%b));
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

/* 
        // mdc de todos os elem de a
        int mdc = a[0];
        for(int i=1;i<n;i++){
            mdc = gcd(mdc, a[i]);
        } */

        // se existe
        
        // vai se manter se tiver cmo trocar elementos iguais de posição
        // se der para colocar o proprio mdc ou os numeros funcdamentais q o compoem, (ex 10 , 25) para o mmc de 5

        int resposta = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                //troca pelo mmc do par, ele sempre vbai ser valido
                ll g = gcd(a[0], a[1]);
                if (a[0] != g){
                    resposta++;
                }
            } 
            else if (i == n - 1) {
                // mesma ideia pelo outro lado
                ll g = gcd(a[n-2], a[n-1]);
                if (a[n-1] != g){
                    resposta++;
                }
            } 
            // se o numero for maior q o mmc dos mdcs que ele compoe, ent elel pode ser o proprio mmc sem perda de info
            // (2 20 5) -> (2 10 5) é equivalente nesse contexto 
            // e por consequencia para cada subarray q ele forme para qualquer lado assim como os anmteriores
            else {
                ll gl = gcd(a[i-1], a[i]);
                ll gr = gcd(a[i], a[i+1]);
                ll mcc = (ll)gl /gcd(gl, gr) * gr;
                if (mcc < a[i]) {
                    resposta++;
                };
            }
        }

        cout << resposta << endl;
    }
}