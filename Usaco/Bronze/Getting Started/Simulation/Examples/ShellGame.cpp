#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);


    int n;
    cin >> n;
    vector<int> pos(3);
    for (int i = 0; i < 3; i++){
        pos[i] = i;
    }
    vector<int> quant(3, 0);

    for(int i=0; i<n; i++){
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--; g--;
        swap(pos[a], pos[b]);
        quant[pos[g]]++;
    }

    int maior = 0;
    for(int i=0; i<3; i++){
        if(maior < quant[i]){
            maior = quant[i];
        }
    }


    cout << maior << endl;
}