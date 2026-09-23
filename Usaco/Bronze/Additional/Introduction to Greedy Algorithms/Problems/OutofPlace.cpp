#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> ordem(n);
    vector<int> original(n);
    for(int i=0; i<n; i++){ 
        cin >> ordem[i];
        original[i] = ordem[i];
    }

    // a ordem de apenas uma PODE esta errada, basta descobrir essa
    // quando não tiver ordenado sempre vai ser o proprio elemento ou o anterior

    // COMO ACHAR O index desse?
    sort(ordem.begin(), ordem.end());

    int total = 0;
    for(int i=0; i<n; i++){
        if(original[i] != ordem[i]) total++;
    }

    if(total) total--;

    cout << total << endl;

}