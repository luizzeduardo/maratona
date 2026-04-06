#include <bits/stdc++.h>
using namespace std;

int main(){

    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        long long bonito = 0;
        int B = sqrt(2*n);

        // Para a[j] > B: poucas iterações por j
        for(int j = 0; j < n; j++){
            if(a[j] <= B) continue;
            
            for(int x = 1; x <= n; x++){
                if(x * a[j] > j) break;
                int i = j - x * a[j];
                if(i >= 0 && a[i] == x){
                    bonito++;
                }
            }
        }

        // Para a[j] ≤ B: fixamos i
        for(int i = 0; i < n; i++){
            if(a[i] > n) continue;
            
            for(int k = 1; k <= B; k++){
                int j = i + a[i] * k;
                if(j < n && a[j] == k){
                    bonito++;
                }
            }
        }

        cout << bonito << endl;
    }
}