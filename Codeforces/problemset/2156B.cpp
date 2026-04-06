#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<pair<char, int>> blocos;
        char atual = s[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == atual) {
                count++;
            } else {
                blocos.push_back({atual, count});
                atual = s[i];
                count = 1;
            }
        }
        blocos.push_back({atual, count});

        // se n tem B O(n) pra descobrir sem ser assim, agr é em O(1)
        bool temB = false;
        for (auto [tipo, _] : blocos) {
            if (tipo == 'B') temB = true;
        }

        vector<int> querry(q);
        for(int i=0; i<q; i++){
            cin >> querry[i]; 
        }

        for(int i=0; i<q; i++){

            if (!temB) {
                // Todas máquinas são A
                cout << querry[i] << " ";
                continue;
            }

            int bloco = 0;
            int count = 0;
            while(querry[i] > 0){
                if(blocos[bloco].first == 'A'){
                    
                    if (querry[i] > blocos[bloco].second) {
                        querry[i] -= blocos[bloco].second;
                        count += blocos[bloco].second;
                    }
                    else{
                        count += querry[i];
                        querry[i] = 0;
                        break;
                    }
                
                }
                else{
                    for (int j = 0; j < blocos[bloco].second; j++) {
                        querry[i] /= 2;
                        count++;
                        if (querry[i] == 0) break;
                    }
                }
                bloco++;
                if(bloco == blocos.size()){
                    bloco = 0;
                }
            }
            cout << count << endl;
        }

        //cout SEMPRE estará entre n e n/2



        // n <= 20, type A ou B, numeradas de 1 a n (i+1)

        //tipo A -> x -= 1
        //tipo B -> x /= 2 (arredonda pra baixo mrm)

        
    }
}