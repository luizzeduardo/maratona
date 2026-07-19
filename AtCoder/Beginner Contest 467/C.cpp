#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n-1);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++){
        cin >> b[i];
    }
    
    // ou é 0 ou é 1 em B
    // M é sempre 2
    // se bi é 0 ent ai + ai+1 tem q ser par
    // se bi é 1 ent ai + ai+1 tem q ser impar


    int melhor = INT_MAX;

    for(int i=0; i<=1; i++){
        int custo = 0;
        if(i != a[0]%2){
            custo++;
        }


        int paridade = i;
        for(int j=0; j<n-1; j++){
            paridade = paridade ^ b[j];
            if(paridade != a[j+1]%2){
                custo++;
            }
        }

        melhor = min(melhor, custo);
    }


    cout << melhor << endl;

}