#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n,q;
    cin >> n >> q;
    vector<int> vacas(n);
    for(int i=0; i<n; i++){
        cin >> vacas[i];
    }

    vector<int> Holsteins(n+1,0);
    vector<int> Guernseys(n+1,0);
    vector<int> Jerseys(n+1,0);


    for(int i=1; i<=n; i++){
        Holsteins[i] += Holsteins[i-1];
        Guernseys[i] += Guernseys[i-1];
        Jerseys[i]   += Jerseys[i-1];
        if(vacas[i-1] == 1) Holsteins[i]++;
        if(vacas[i-1] == 2) Guernseys[i]++;
        if(vacas[i-1] == 3) Jerseys[i]++;
    }

    while(q--){
        int inicio, fim;
        cin >> inicio >> fim;
        inicio--;

        cout << Holsteins[fim] - Holsteins[inicio] << " ";
        cout << Guernseys[fim] - Guernseys[inicio] << " ";
        cout << Jerseys[fim]   - Jerseys[inicio];
        cout << endl;

    }


}