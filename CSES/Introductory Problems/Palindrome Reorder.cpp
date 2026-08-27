#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    string s;
    cin >> s;

    // para que uma palavra seja um palindromo, podemos ver a repetição das palavras

    // se eu tenho uma palavra de tamanho par, qualquer quantidade impar impede
    // se for uma string impar, só podemos ter uma letra de quantidade impar, mais q isso tbm é inválido

    vector<int> quant_s(26,0);

    for(char c: s){
        quant_s[c - 'A']++;
    }

    int quant = 0;
    int impar  = -1;
    for(int i=0; i<26; i++){
        if(quant_s[i]%2 == 1){
            quant++;
            impar = i;
        }

    }
    
    if(quant > s.size()%2){
        cout << "NO SOLUTION" << endl;
        return 0;
    }


    string metade;
    metade.reserve(s.size()/2);
    for(int i=0; i<26; i++){
        metade.append(quant_s[i]/2, char('A' + i));
    }

    string res;
    res.reserve(s.size());
    res += metade;
    if(impar != -1) res += char('A' + impar);
    res.append(metade.rbegin(), metade.rend());


    cout << res << endl;
}