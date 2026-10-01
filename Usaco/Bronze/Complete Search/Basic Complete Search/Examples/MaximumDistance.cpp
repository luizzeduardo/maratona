#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> pontos(n);
    for(int i=0; i<n; i++){
        cin >> pontos[i].first;
    }
    for(int i=0; i<n; i++){
        cin >> pontos[i].second;
    }

    int maior = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i ==j) continue;
            int x = abs(pontos[i].first - pontos[j].first);
            int y = abs(pontos[i].second - pontos[j].second);
            x = pow(x, 2);
            y = pow(y, 2);
            if(maior < x+y){
                maior = x+y;
            }
        }
    }

    cout << maior << endl;
}

// Codeforces: https://codeforces.com/gym/102951/problem/A