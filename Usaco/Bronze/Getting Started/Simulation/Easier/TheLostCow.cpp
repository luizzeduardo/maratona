#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;
    int dis = abs(x-y);
    int n = 0;

    // à direita 1 4 16... potencias de 4
    // à esqueda 2 8 32.. potencias de 4/2
    if(x < y){
        // direita
        while(pow(2, n) < dis){
            n+=2;
        }
    }
    else{
        //esquerda
        n++;
        while(pow(2, n) < dis){
            n+=2;
        }
    }

    // 1, 3, 6, 12, 24,...

    int total = pow(2, n+1) -2 + dis;

    cout <<  total << endl;



}