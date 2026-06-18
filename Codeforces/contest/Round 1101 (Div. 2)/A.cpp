#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        } 

        sort(a.begin(), a.end());

        int mediana = a[n/2];

        int menores = 0;
        int maiores = 0;

        for(int amigo : a){
            if(amigo < mediana){
                menores++;
            } 
            else if(amigo > mediana){
                maiores++;
            } 
        }

        cout << max(menores, maiores) << endl;
    }
}

// A mediana sempre vai ser a melhor opção
// basta saber quantos elementos diferentes dela são maiores e menores
// depois basta tirar a diferença por fim