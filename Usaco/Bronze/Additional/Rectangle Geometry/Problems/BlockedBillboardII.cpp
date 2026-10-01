#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int intersec(int a1, int a2, int b1, int b2){
    int valor = max(min(a2, b2) - max(a1, b1), 0);
    return valor;
}

int main(){

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int ax1, ay1, ax2, ay2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;    
    int bx1, by1, bx2, by2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int largura = (ax2-ax1); int altura = (ay2-ay1);

    int larguraInter = intersec(ax1, ax2, bx1, bx2);
    int alturaInter = intersec(ay1, ay2, by1, by2);

    if(largura == larguraInter && (by1<ay1 || by2>ay2)){
        altura -= alturaInter;
    }
    else if(altura == alturaInter && (bx1<ax1 || bx2>ax2)){
        largura -= larguraInter;
    }

    cout << altura*largura << endl;
}