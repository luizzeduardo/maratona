#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;

    vector<string> hps(n);
    for(int i=0; i<n; i++){
        cin >> hps[i];
    } 

    vector<int> h(n+1, 0);
    vector<int> p(n+1, 0);
    vector<int> s(n+1, 0);

    for(int i=1; i<n+1; i++){
        if(hps[i-1] == "H") p[i]++;
        if(hps[i-1] == "P") s[i]++;
        if(hps[i-1] == "S") h[i]++;
        p[i]+=p[i-1];
        h[i]+=h[i-1];
        s[i]+=s[i-1];
    }

    int maior = INT_MIN;
    for(int i=0; i<n+1; i++){

        maior = max(maior, s[i]+ p[n]-p[i]);
        maior = max(maior, s[i]+ h[n]-h[i]);

        maior = max(maior, h[i]+ p[n]-p[i]);
        maior = max(maior, h[i]+ s[n]-s[i]);

        maior = max(maior, p[i]+ h[n]-h[i]);
        maior = max(maior, p[i]+ s[n]-s[i]);

    }

    cout << maior << endl;


}