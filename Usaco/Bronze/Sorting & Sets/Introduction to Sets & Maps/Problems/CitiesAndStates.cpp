#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n;
    cin >> n;

    map<string, int> codeCidade;

    int total = 0;
    for(int i=0; i<n; i++){
        string cidade;
        cin >> cidade;
        string code;
        cin >> code;
        string city = cidade.substr(0, 2);
        if(city == code) continue;

        string teste = city+code;
        string esse = code+city;
        

        if(codeCidade[teste] > 0) total+= codeCidade[teste];
        codeCidade[esse]++;
    }

    cout << total << endl;
}