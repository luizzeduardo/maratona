#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> compra(n);
    vector<int> venda(n);

    for(int i=0; i<n; i++){
        cin >> compra[i] >> venda[i];
    }

    vector<int> prefix(n);
    prefix[0] = compra[0] - venda[0];

    for(int i=1; i<n; i++){
        prefix[i] += prefix[i-1] + compra[i] - venda[i];
    }

    int q;
    cin >> q;
    while(q--){
        int consulta;
        cin >> consulta;
        consulta--;
    

        if(prefix[consulta] > 0) cout << "COMPRA" << endl;
        else if(prefix[consulta] < 0) cout << "VENDA" << endl;
        else cout << "NEUTRO" << endl;
    }
}