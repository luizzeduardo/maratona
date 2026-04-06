#include <bits/stdc++.h>
using namespace std;

int abs(int a){
    if(a>0){
        return a;
    }
    else{
        return -1*a;
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
        int resposta = 0;
        int meus = 0;
        bool fim = false;
        bool inicio = false;

        if(a[0] == -1){
            inicio =true;
        }
        if(a[n-1] == -1){
            fim = true;
        }

        // condição
        if(fim && inicio){
        }
        else if(fim){
            meus = a[0];
        }
        else if(inicio){
            meus = a[n-1];
        }
        else{
            resposta = a[0] - a[n-1];
            resposta = abs(resposta);
        }


        cout << resposta << endl;
        for(int i=0; i<n; i++){
            if(a[i]==-1){
                if(i==0 || i == n-1){
                    cout << meus << " ";
                }
                else{
                    cout << 0 << " ";
                }
                
            }
            else{
                cout << a[i] << " ";
            }
        }
        cout << endl;

    }
}

// mtt feio mas deve funcionar perfeitamente