#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, l;
        cin >> n >> m >> l;

        vector<int> light(n);
        for(int i; i<n; i++){
            cin >> light[i];
        }
        int x = 0;

        //m -> animatronics
        //l -> quant de seg na noite
        // nivel de perigo de um dos m animnatronics vai aumentar em 1 a cada 1 seg da noite
        //n -> quant de flash light q podemos usar
    
    

        //l == n -> x=0
        //l < n -> x=  l - l/m, no tempo n[i], n[i] == l
        // variavel aux da distancia entre as flash lights e valor l/m

        int total = 0;
        int dist = 0; //  distancia l entre flash light
        

        for(int flash : light){
            int total = flash;
            //reduzir agr
            if(total<m){
                total--;
                dist += m - total;
            }

            if()
            
        }
    }
}