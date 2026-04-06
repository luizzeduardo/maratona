#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int pontos = 0;
        int S = 1;
        // faz task pontos += S* a.first, mas  S -= S*(1 - a.second/100)
        // programaçaõ dinamica
        // ordem fixa das tarefas
        vector<pair<int, int>> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i].first >> a[i].second;
        }
    }
        
}