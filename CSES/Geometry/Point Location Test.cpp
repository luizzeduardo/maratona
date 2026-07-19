#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // existe uma linha que passa pelos pontos p1 2 p2 sempre
        // se p3 está no mesmo ponto a proporção entre os pontos sempre será igual

        // n podemos ver a razão de ium ponto sozinho, isso permite inconsistencias como divisão por zero
        // a proporção p1y-p2y/p1x-p2x é igual para quaisquer pontos dentro da linha q passa por p1 e p2
        // se p3 faz parte dessa reta, então, a proporção p1y-p2y/p1x-p2x == p1y-p3y/p1x-p3x
        // caso contrário ela estará abaixo ou acima da reta, de acordo com a proporção

        // Logo basta calcular as proporcoes e ver a diferença (dif)

        // Se dif == 0 -> TOUCH
        // Se dif < 0 -> LEFT
        // Se dif > 0 -> RIGHT

        ll dif = (y2 - y1)*(x3 - x1) - (y3 - y1)*(x2 - x1);

        cout << endl;

        if(dif == 0){
            cout << "TOUCH";
        }
        else if(dif < 0){
            cout << "LEFT";
        }
        else{
            cout << "RIGHT";
        }
        
        
    }
}