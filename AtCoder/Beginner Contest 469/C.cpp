#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){
    int n;
    cin >> n;

    string s; // ex: oxoxoxoxox
    // o -> hit 
    // x -> miss
    // só pode continuar se tiver ainda hit
    // toda nova bag precisa descatar uma hit

    // devemos mostrar quantas bags ele pode pegar, considertando todas as k possibilidades iniciais (1, n)


    cin >> s;
    vector<int> primeiro(n+1);
    int aux = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'x'){
            aux++;
            primeiro[aux] = i+1;
        }
    }

    for(int i=1; i<n+1 ;i++){
        if(primeiro[i] != 0){
            cout << primeiro[i] << endl;
        }
        else{
            cout << n << endl;
        }
    }

}