#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;
    vector<int>trocas(n);
    for(int i=0; i<n; i++){
        cin >> trocas[i];
        trocas[i]--;
    }

    vector<int> inversa(n);
    for(int i=0; i<n; i++){
        inversa[trocas[i]] = i;
    }

    vector<int>ids(n);
    for(int i=0;i<n; i++){
        cin >> ids[i];
    }


    for(int i=0; i<3; i++){
        vector<int> antes(n);
        for (int i = 0; i < n; i++) {
            antes[i] = ids[trocas[i]];
        }
        ids = antes;
    }

    for(int i=0; i<n; i++){
        cout << ids[i] << endl;
    }
}