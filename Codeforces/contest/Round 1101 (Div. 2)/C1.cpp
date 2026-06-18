#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, s;
        cin >> n >> x >> s; // <=3000 3.10^3 O(n^2)
        string pessoas;
        cin >> pessoas;


        int total = 0;
        int mesasLivres = x;
        vector<int> dp(x, s); //quantidade de cadeiras livres por mesa
        for(char pessoa : pessoas){
            for(int i=0; i<x; i++){
                if(pessoa == 'I'){
                    if(dp[i] == s){
                        dp[i]--;
                        mesasLivres--;
                        break;
                    }
                }
                else if(pessoa == 'E'){
                    if(dp[i] < s && dp[i] > 0){
                        dp[i]--;
                        break;
                    }
                }
                else{
                    // porra
                }
            }
        }


        //Ambiverts sempre vão entrar
        // A sua unica restrição n é para sentar mas onde

        //introvertidos sempre devem ser os primeiros no melhor caso
        //só podemos ter x introvertidos no maixmo

        // extrovertidos n entram se  houver apenas mesas vazias ou cheias
        // nomaixmo podemos ter x(s-1) extrovertidos

    }

        /*     

        x -> qunat de MESAS
        s -> quant de CADEIRAS

        Introverts (I) who have to sit at an empty table
        Extroverts (E) who have to sit at a non-empty table
        Ambiverts (A) who can sit at any table. 

        */
}