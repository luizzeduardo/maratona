#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int c;
    cin >> c;
    int k;
    cin >> k;
    vector<int> d(n);
    for(int i=0; i<n; i++){
        cin >> d[i];
    }

    int total = k+c;
    for(int i=1; i<n; i++){
        int continuo = c*(d[i]-d[i-1]);
        int separado = k + c;
        int melhor = min(continuo, separado);
        total += melhor;
    }

    cout << total << endl;

}