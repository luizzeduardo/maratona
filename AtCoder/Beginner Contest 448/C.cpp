#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    //n >= 6

    vector<int> a(n+1);
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    //se estiver ordenado fica masi fácil
    vector<pair<int, int>> ordenado;
    for(int i=1; i<n+1; i++){
        ordenado.push_back(pair<int, int>(a[i], i));
    }
    sort(ordenado.begin(), ordenado.end());

    while(q--){
        int tam;
        cin >> tam;
        vector<int> query(tam+1, 0);
        for(int i=1; i<tam+1; i++){
            cin >> query[i];
        }

        int menor = INT_MAX;
        for (auto &p : ordenado) {
            bool pode = true;
            for(int i=1; i<tam+1; i++){
                if(p.second == query[i]){
                    menor = p.first;
                    pode = false;
                }

            }
            if(pode){
                menor = p.first;
                break;
            }
        }
        cout << menor << endl;

    }
}