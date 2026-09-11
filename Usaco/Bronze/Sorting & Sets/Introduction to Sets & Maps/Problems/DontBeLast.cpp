#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    vector<string> names = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

    int n;
    cin >> n;
    map<string, int> cows;
    for(int i=0; i<n; i++){
        string cow;
        cin >> cow;
        int milk;
        cin >> milk;
        cows[cow] += milk;
    }

    int primeiro = INT_MAX;
    string primeiro_nome = "Tie";
    int segundo = INT_MAX;
     string segundo_nome = "Tie";

    for(string nome: names){
        if(cows[nome] < primeiro){
            segundo = primeiro;
            segundo_nome = primeiro_nome;
            primeiro = cows[nome];
            primeiro_nome = nome;
        }
        else if(cows[nome] > primeiro){
            if(cows[nome] < segundo){
                segundo = cows[nome];
                segundo_nome = nome;
            }
            else if(cows[nome] == segundo){
                segundo_nome = "Tie";
            }
        }
        else{
            primeiro_nome = "Tie";
        }
    }

    cout << segundo_nome << endl;
}