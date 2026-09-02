#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> dormi(n);
        vector<int> prefix(n, 0);
        cin >> dormi[0];
        prefix[0] = dormi[0];
        for(int i=1; i<n; i++){
            cin >> dormi[i];
            prefix[i] = prefix[i-1] + dormi[i];
        }

        if(prefix[n-1] == 0){
            cout << 0 << endl;
            return 0;
        }

        set <int> candidatos;
        for(int i=0; i<n; i++){
            if(prefix[i] > 0){
                if(prefix[n-1]%prefix[i] == 0) candidatos.insert(i);
            }
        }

        if(candidatos.size() == 0){
            cout << n-1 << endl;
            return 0;
        } 

        int mov = INT_MAX;
        for(int cand : candidatos){
            int local = cand;
            int quant = 1;
            int ultimo = cand;
            for(int j=cand+1; j<n; j++){
                if(prefix[j] == prefix[cand] * (quant + 1)){
                    local += j - ultimo - 1;
                    quant++;
                    ultimo = j;
                }
            }

            if(quant == prefix[n-1]/prefix[cand]){
                mov = min(mov, local);
            }
        }

        cout << mov << endl;

    }
}