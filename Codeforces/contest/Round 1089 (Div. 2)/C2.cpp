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

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
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

        // se existe
        
        // vai se manter se tiver cmo trocar elementos iguais de posição
        // se der para colocar o proprio mdc ou os numeros funcdamentais q o compoem, (ex 10 , 25) para o mmc de 5


        //o easy
/*         int resposta = 0;
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
        } */


        // o hard
        int resposta = 0;

        for (int i = 0; i < n; i++) {
            // mdc por array
            ll l;

            if (i == 0) { // [0, n] -> 0 + [1, n]
                ll g = gcd(a[0], a[1]);
                l = g;
            } 
            else if (i == n - 1) {
                ll g = gcd(a[n - 2], a[n - 1]);
                l = g;
            } 
            else {
                ll gl = gcd(a[i - 1], a[i]);
                ll gr = gcd(a[i], a[i + 1]);
                l = lcm(gl, gr);
            }

            // se tem algum multiplo de l no b

            // se o mdc é maior n pode mudar
            if (l > b[i]) continue;

            // mesmo do easy
            if (l != a[i]) {
                resposta++;
            } 
            // se é multiplo
            else {
                /* int mul = l;
                while(mul<b[i]){
                    mul+=l;
                    if (mul <= b[i]) {
                        resposta++;
                        break;
                    }
                } */
                if( 2 *l <= b[i]){
                    
                }
            }
        }

        cout << resposta << endl;
    }
}