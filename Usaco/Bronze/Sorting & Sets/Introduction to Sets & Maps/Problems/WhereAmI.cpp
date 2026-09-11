#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    cin >> n;
    // basta ver a primeira maior sequencia única da string em questão
    // n<=100  ----> O(n³) passa de qualquer forma

    string s;
    cin >> s;
    for(int i=1; i<=n; i++){

        unordered_set <string> vistos;
        bool unico = true;

        for(int j=0;j+i<=n; j++){
            string sub = s.substr(j, i);
            if(vistos.count(sub) == 1){ 
                unico = false;
                break;
            }
            vistos.insert(sub);
        }

        if(unico){ 
            cout << i << endl;
            return 0;
        }
    }

    
}