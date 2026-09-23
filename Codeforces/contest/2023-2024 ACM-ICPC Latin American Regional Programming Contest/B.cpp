#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    map<int, int> a;
    for(int i=0; i<n*3; i++){ 
        int aux;
        cin >> aux;
        a[aux]++;
    }


    bool tres = true;
    for(auto[chave, valor]: a){
        if(valor%3 != 0){ 
            tres = false;
            break;
        }
    }

    if(tres) cout << "N" << endl;
    else cout << "Y" << endl;
}