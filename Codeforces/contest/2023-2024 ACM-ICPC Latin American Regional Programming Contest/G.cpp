#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll U1 = LLONG_MIN;
ll U2 = LLONG_MAX;
ll V1 = LLONG_MIN;
ll V2 = LLONG_MAX;
map<tuple<bool, bool, bool, bool>, bool> cache;
vector<pair<ll, ll>> resp;

bool validoTodos(ll u, ll v, ll n, vector<pair<ll, ll>> &pos, vector<ll> &dist){
    ll x = (u+v)/2;
    ll y = (u-v)/2;

    for(int i=0; i<n; i++){
        ll d = llabs(x - pos[i].first) + llabs(y - pos[i].second);
        if(d != dist[i]) return false;
    }
    return true;
}


void testa(ll u, ll v, ll n, vector<pair<ll, ll>> &pos, vector<ll> &dist){
    if((u+v)%2 != 0) return;

    tuple<bool,bool,bool,bool> tipo = make_tuple(u == U1, u == U2, v == V1, v == V2);

    if(cache.count(tipo) == 0){
        cache[tipo] = validoTodos(u, v, n, pos, dist);     
    }

    if(cache[tipo]){
        resp.push_back({(u + v) / 2, (u - v) / 2});
    }

}


int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pos(n);
    vector<ll> dist(n);
    for(int i=0; i<n; i++){
        cin >> pos[i].first;
        cin >> pos[i].second;
        cin >> dist[i];
    }

    // d = |x-a| + |y-b|, onde sabemos a, b e d
    // isso é relativo à apenas UMA antena
    // Para uma resposta (x, y) ser válida ela deve valer para TODAS as antenas

    // d = |x - a| + |y - b|
    // |x−a| + |y−b|  =  max( |(x−a)+(y−b)|, |(x−a)−(y−b)| )
    // s = x-a
    // t = y-b
    // |s| + |t| = max(|s + t|, |s - t|)

    // Logo, |s + t|, |s - t| <= d


    for(int i=0; i<n; i++){
        ll UE = pos[i].first + pos[i].second - dist[i];
        ll UD = pos[i].first + pos[i].second + dist[i];
        ll VE = pos[i].first - pos[i].second - dist[i];
        ll VD = pos[i].first - pos[i].second + dist[i];

        U1 = max(U1, UE);
        U2 = min(U2, UD);
        V1 = max(V1, VE);
        V2 = min(V2, VD);
    }

    // U1 - U2 
    // V1 - V2
    // É o retângulo que contem todas as respostas válidas

    // x = (u+v)/2
    // y = (u-v)/2
    // Logo u + v deve ser par

    // Todas as respostas válidas de (x, y) vão estar na borda desse retangulo
    for(ll u = U1; u <= U2; u++){
        testa(u, V1, n, pos, dist);
        testa(u, V2, n, pos, dist);
    }
    for(ll v = V1; v <= V2; v++){
        testa(U1, v, n, pos, dist);
        testa(U2, v, n, pos, dist);
    }

    sort(resp.begin(), resp.end());
    resp.erase(unique(resp.begin(), resp.end()), resp.end());   

    for(int i = 0; i < (int)resp.size(); i++){
        cout << resp[i].first << " " << resp[i].second << endl;
    }
}



