#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> pos(n+1, 0);        
    for(int i = 0; i < n; i++) if(a[i]) pos[a[i]] = i + 1;

    vector<int> cres;                
    for(int i = 0; i < n; i++) if(a[i]) cres.push_back(i);

    vector<int> prox(n+2, 0);           
    for(int i = n; i >= 1; i--){
        if(pos[i] != 0) prox[i] = i; 
        else prox[i] = prox[i+1];
    }

    vector<int> resposta(n, 0);

    int low = 0;
    int high = cres.size() - 1;
    int base = 0; 
    int topo = n - 1;
    int v = 1;
    bool ok = true;

    while (base <= topo) {
        while (low <= high && cres[low] < base) low++;
        while (low <= high && cres[high] > topo) high--;

        // já ta 
        if (pos[v] != 0) {                                
            int p = pos[v] - 1;
            if (p == base) { 
                resposta[p] = v; 
                base++; 
            }
            else if (p == topo) { 
                resposta[p] = v; 
                topo--; 
            }
            else { 
                ok = false; 
                break; 
            }
        }

        // pode qualquer um
        else if (low > high) {                               
            resposta[topo] = v; 
            topo--;
        }

        // fixa dps
        else {
            int menor = prox[v];
            int posMenor = pos[menor] - 1;
            int LimiteInf = cres[low];
            int LimiteSup = cres[high];
            int falta = menor - v;

            bool podeEsq = false, podeDir = false;

            //ponta esquerda
            if (posMenor == LimiteInf) {
                int esquerda = posMenor - base;     
                int direita = falta - esquerda;           
                if (esquerda >= 0 && esquerda <= falta && direita <= topo - LimiteSup) {
                    if (esquerda >= 1) podeEsq = true;
                    if (direita >= 1) podeDir = true;
                }
            }

            // ponta direita
            if (posMenor == LimiteSup) {
                int direita = topo - posMenor;
                int esquerda = falta - direita;
                if (direita >= 0 && direita <= falta && esquerda <= LimiteInf - base) {
                    if (esquerda >= 1) podeEsq = true;
                    if (direita >= 1) podeDir = true;
                }
            }

            if (podeEsq) { 
                resposta[base] = v; 
                base++; 
            }
            else if (podeDir) { 
                resposta[topo] = v; 
                topo--; 
            }
            else { 
                ok = false; 
                break;
            }
        }

        v++;
    }

    if (!ok) { 
        cout << "*" << endl; 
        return 0; 
    }

    for(int i=0; i<n; i++){ 
        cout << resposta[i];
        if(i!=n-1) cout << " ";
    }
    cout << endl;
}