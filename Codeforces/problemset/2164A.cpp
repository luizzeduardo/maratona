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
            cin>> a[i];
        }
        int x;
        cin >> x;

        //numeros devem se adjacentes
        // substitui por um elemento q esetja no intervalo dos dois numeros
        //tentar fazer o final num ser x
        //basta saber se existe algum numero menor q x e algum maior q x
        bool maior = false;
        bool menor = false;
        for(int i=0; i<n; i++){
            if(a[i] > x){
                maior = true;
            } 
            else if(a[i] < x){
                menor = true;
            }
            else if(a[i] == x){
                maior = true;
                menor = true;
            }
        }

        if(maior && menor){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}