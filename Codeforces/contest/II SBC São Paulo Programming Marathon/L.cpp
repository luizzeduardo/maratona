#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    if(scanf("%d", &n) != 1) return 0;
    vector<int> P(n);
    for(int i = 0; i < n; i++) scanf("%d", &P[i]);

    vector<vector<ll>> f(n, vector<ll>(n, 0));
    auto F = [&](int lo, int hi) -> ll {
        if(lo > hi) return 0;          // intervalo vazio
        return f[lo][hi];
    };

    vector<int> T(n);          // chaves de [lo,hi] em ordem de chegada
    vector<int> posInT(n);     // posInT[valor] = indice em T
    vector<ll>  diff(n + 2);   // difference array para o span

    for(int len = 1; len <= n; len++){
        for(int lo = 0; lo + len - 1 < n; lo++){
            int hi = lo + len - 1;

            int m = 0;
            for(int j = 0; j < n; j++){
                int v = P[j];
                if(v >= lo && v <= hi){
                    T[m] = v;
                    posInT[v] = m;
                    m++;
                }
            }

            for(int v = lo; v <= hi + 1; v++) diff[v] = 0;
            for(int j = 0; j + 1 < m; j++){
                int a = min(T[j], T[j+1]);
                int b = max(T[j], T[j+1]);
                diff[a + 1] += 1;   // +1 em [a+1, b-1]
                diff[b]     -= 1;
            }

            ll running = 0, best = 0;
            for(int u = lo; u <= hi; u++){
                running += diff[u];
                ll span = running;

                ll bridge = 0;              // aresta "ponte" criada ao remover u
                int p = posInT[u];
                if(p - 1 >= 0 && p + 1 < m){
                    int L = T[p-1], R = T[p+1];
                    int less = (L < u) + (R < u);
                    if(less == 1) bridge = 1;
                }

                ll cost = span + bridge;
                ll val  = cost + F(lo, u - 1) + F(u + 1, hi);
                best = max(best, val);
            }
            f[lo][hi] = best;
        }
    }

    printf("%lld\n", F(0, n - 1));
    return 0;
}