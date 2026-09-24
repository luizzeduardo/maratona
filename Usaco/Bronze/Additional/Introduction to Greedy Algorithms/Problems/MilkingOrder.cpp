#include <bits/stdc++.h>
using namespace std;

int main(){
    
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(m);
    for(auto &x : h) cin >> x;

    vector<int> resp(n, -1), posDe(n + 1, -1); // posDe[vaca] = posição fixada
    for(int i = 0; i < k; i++){
        int c, p; cin >> c >> p; p--;
        resp[p] = c;
        posDe[c] = p;
    }

    // caso 1: vaca 1 já fixa
    if(posDe[1] != -1){ cout << posDe[1] + 1 << "\n"; return 0; }

    bool umNaH = find(h.begin(), h.end(), 1) != h.end();

    if(umNaH){
        // caso 2: hierarquia o mais cedo possível
        int p = 0;
        for(int j = 0; j < m; j++){
            if(posDe[h[j]] != -1){ p = posDe[h[j]] + 1; continue; }
            while(resp[p] != -1) p++;
            resp[p] = h[j];
            if(h[j] == 1){ cout << p + 1 << "\n"; return 0; }
            p++;
        }
    } else {
        // caso 3: hierarquia o mais tarde possível
        int p = n - 1;
        for(int j = m - 1; j >= 0; j--){
            if(posDe[h[j]] != -1){ p = posDe[h[j]] - 1; continue; }
            while(resp[p] != -1) p--;
            resp[p] = h[j];
            p--;
        }
        for(int i = 0; i < n; i++)
            if(resp[i] == -1){ cout << i + 1 << "\n"; return 0; }
    }
}