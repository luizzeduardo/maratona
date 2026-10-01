#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    while(n--){
        int x;
        cin >> x;

        int vel = 0;
        int metros = 0;
        int resp=0;
        

        while(metros < k){
            int dist = abs(vel-x);
            int maior = (vel-1)*(vel)/2;
            int menor = (x+1)*(x)/2;
            int valor = abs(maior - menor);

            // verificar se pode aumentar
            if(x<vel){
                
                if(k - (metros + vel+1) > valor+vel){
                    vel++;
                }
                // verificar se mantem
                else if(k - (metros + vel) > valor){
                    //mantem
                }
                // senão diminui
                else{

                    vel--;
                }
            }
            else if(vel == x){
                // mater no minimo
                if(k - (metros + vel+1) > valor){
                    vel++;
                }
            }
            // vel < x
            else vel++;
            metros+=vel;
            resp++;
        }
        cout << resp << endl;
    }
}