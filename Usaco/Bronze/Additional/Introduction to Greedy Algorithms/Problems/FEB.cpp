#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (count(s.begin(), s.end(), 'F') == n) {
        cout << n << endl;
        for (int i = 0; i < n; i++) cout << i << endl;
        return 0;
    }


    //primeiro conta a quantidade de grupos q tem indepedente do 'F'
    ll total = 0;
    for(int i=0; i<n-1; i++){
        if(s[i] != 'F'){
            if(s[i] == s[i+1] ) total++;
        }
    }

    // depois é basicamente pegar os grupos de F
    // as possibilidades de cada bloco são definidas pelo tamnho do bloco e elementos na borda dele
    // ex: BFFFFFFB, a borda é B e B

    // Calculamos todos os casos e somamos de baixo para cima de todas as forma possiveis 
    // os incrementos são de 2 em 2, ou seja ou é 0, 2, 4... ou é 1, 3, 5...

    int lo = total;
    int hi = total;
    int i = 0;
    int passo = 2;
    while (i < n) {
        if (s[i] != 'F') { i++; continue; }
        int j = i;
        while (j < n && s[j] == 'F') j++;
        int k = j - i;              
        if (i == 0 || j == n) {      
            hi += k;                 
            passo = 1;
        } else if (s[i-1] == s[j]) { 
            hi += k + 1;
            lo += (k + 1) % 2;
        } else {                   
            hi += k;
            lo += k % 2;
        }
        i = j;
    }


    vector<int> resp;
    for(int i=lo; i<=hi; i+=passo) resp.push_back(i);
    cout << resp.size() << endl;
    for(int resposta : resp){
        cout << resposta << endl;
    }
}