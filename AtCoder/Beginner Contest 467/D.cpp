#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
 
        // ponto P e Q são circulo 1
        // ponto R e S são do circulo 2
        // C1 e C2 tem o mesmo centro

        // ver as retas dos pontos PQ e RS e ver se elas tme algum ponto onde se cruzam
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        ll ux = qx-px;
        ll uy = qy-py;

        ll vx = sx-rx;
        ll vy = sy-ry;

        ll cruza = ux*vy - uy*vx;

        if(cruza != 0){
            cout << "Yes" << endl;
        }
        else{
            // só vale retas paralelas quando são a mesma reta
            ll wx = rx+sx-px-qx;
            ll wy = ry+sy-py-qy;
            ll paralelas = wx*ux + wy*uy;
            if(paralelas){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
        }
    }
}