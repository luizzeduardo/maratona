#include <bits/stdc++.h>
using namespace std;

int paridade(int n){
    if(n%2 == 0){
        return 0;
    } 
    else{
        return 1;
    }
}

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
        //todos os a[i] são unicos entre si

        //ver se a sequencia é se par, impar, pa, impar

        bool pos = true;
        int ant = paridade(a[0]);
        // 0 = par ,1 = impar
        for(int i=1; i<n; i++){
            if(paridade(a[i]) == ant){
                pos = false;
                break;
            }
            ant = paridade(a[i]);
        }

        if(pos){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}