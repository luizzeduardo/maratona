#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int intersec(int a1, int b1, int a2, int b2){
    int inter = max(min(b1, b2) - max(a1, a2), 0);
    return inter;
}


int main(){

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;

    int bx1, bx2, by1, by2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int cx1, cx2, cy1, cy2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    int total = 0;
    total += (ax2 - ax1)*(ay2 - ay1);
    total += (bx2 - bx1)*(by2 - by1);

    // 1 quadrante
    int tira = 0;
    tira += intersec(ax1, ax2, cx1, cx2) * intersec(ay1, ay2, cy1, cy2);
    tira += intersec(bx1, bx2, cx1, cx2) * intersec(by1, by2, cy1, cy2);

    cout << total - tira << endl;
}