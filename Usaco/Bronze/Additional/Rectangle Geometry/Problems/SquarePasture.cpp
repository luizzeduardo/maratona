#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int menorX = min(ax1, bx1);
    int maiorX = max(ax2, bx2);
    int menorY = min(ay1, by1);
    int maiorY = max(ay2, by2);

    int maior = max(maiorX - menorX, maiorY - menorY);

    cout << maior*maior << endl;

}