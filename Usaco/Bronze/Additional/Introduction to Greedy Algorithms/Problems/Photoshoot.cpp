#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    //ou nós temos um par onde GH, HG, HH, GG
    // HH ou GG nõa faz diferença inverter
    // GH melhora
    // HG piora

    int inversoes = 0;
    int maior = n - n%2;
    bool inverte = false;
    for(int i=maior-1; i>=0; i-=2){
        if(s[i] == 'H' && s[i-1] == 'G' && !inverte){ inversoes++; inverte=true;}
        if(s[i] == 'G' && s[i-1] == 'H' && inverte){ inversoes++; inverte=false;}
    }
    //GG GH GH HG HH HG HG
    //GG HG HG

    cout << inversoes << endl;
}