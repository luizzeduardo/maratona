#include <bits/stdc++.h>
using namespace std;
 
int main(){
    //entrada de dados
    int t;
    cin >> t;
    while(t--){
        int n, m, h;
        cin >> n >> m >> h;
 
        vector<int> a(n);
        vector<int> copy(n);
        vector<int> foi(n, -1);
        vector<int> quando(n, 0);

        for(int i =0; i<n; i++){
            cin >> a[i];
            copy[i] = a[i];
        }
        vector<int> b(m);
        vector<int> c(m);
        int quebro = 0;
        
        for(int i = 0; i < m; i++){

            cin >> b[i] >> c[i];
            b[i]--; // 0-based
        }

        for(int i = 0; i < m; i++){
            if(quando[b[i]] == quebro){
                a[b[i]] += c[i];
            }
            else{
                a[b[i]] = copy[b[i]] + c[i];
                quando[b[i]] = quebro;
            }
            if(a[b[i]] > h){
                a[b[i]] = copy[b[i]];
                quebro++;
            }
        }
 
        for(int i=0; i<n; i++){
            if(quando[i] == quebro){
                cout << a[i] << " ";
            }
            else{
                cout << copy[i] << " ";
            }
        }
        cout << endl;
 
 
 
    }
}