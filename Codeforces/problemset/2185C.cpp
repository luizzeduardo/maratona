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
 
        //ordenar vetor
        sort(a.begin(), a.end());
 
 
        //achar o MEX
        int maior = 1;
        int seq = 1;
        int num = a[0];
        for(int i=1; i<n; i++){
            if(num+1 == a[i]){
                seq++;
                if(seq > maior){
                    maior = seq;
                }
            }
            else if(num+1 < a[i]){
                seq = 1;
            }
    
            num = a[i];
        }
 
        cout << maior << endl;
    }
}