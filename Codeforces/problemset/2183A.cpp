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

        // apenas 0 e 1 no array
        //alice = 0
        //bob = 1

        //Se existe 0 no intervalo [l,r] de a -> substitui 1,
        //Se todos elem no intervalo [l,r] de a são 1 -> substitui 0

        //alice joga primeiro

        //bob ganha 0,0,0,0... (independente do tamanho, na vez dele) ou [0,0] na vez da alice
        //alice ganha 1,1,1,1,1... (independente do tamanho na vez dela) ou [1,1] na vez do bob

        //se em qualquer momento, algum comseguir deixar tudo com apenas um tipo, acabou

        //alice só ganha se conseguir trasformar TODOS em 1 na sua jogada (CONSIDERANDO QUE EXISTE PELO MENOS UM 0), caso contrário, existindo um unico zero na vez de Bob, Bob ganha. Ela só consegue fazer isso se , PELO MENOS, um dos extremos da lista forem 1, pois como existe ao menos 1 zero basta trasformar tudo de um dos lados para 1.

        //Assim, basta ve se a primeira ou útima posiçaõ da lista é 1 ou não


        if (a[0] == 0 && a[n-1] == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}