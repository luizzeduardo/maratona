#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int a = m/x+1;
    int b = m/y+1;
    int maior = INT_MIN;
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            int num = i*x + j*y;
            if(num > m) continue;
            if(maior < num){
                maior = num;
            }
        }
    }

    cout << maior <<  endl;
}