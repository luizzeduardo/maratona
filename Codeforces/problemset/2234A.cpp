#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        //deve ser decrescente
        // Ai+2 = (Ai mod Ai+i) para todo i

        // Ai+2 < Ai+1 estritamente decrescente

        sort(b.rbegin(), b.rend());   // ordem decrescente

        bool pode = true;
        
        for (int i = 0; i + 2 < n; i++) {
            if (b[i + 2] != b[i] % b[i + 1]) { 
                pode = false; 
                break; 
            }
        }

        if(pode){
            cout << b[0] << " " << b[1] << endl;
        }
        else{
            cout << -1 << endl;
        }

    }
}