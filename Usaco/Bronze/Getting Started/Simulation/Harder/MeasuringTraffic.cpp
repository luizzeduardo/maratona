#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> sensores(n);
    vector<pair<int, int>> intervalo(n);
    for(int i=0; i<n; i++){
        cin >> sensores[i];
        cin >> intervalo[i].first;
        cin >> intervalo[i].second;

    }
    pair<int, int> sai = make_pair(0,0);
    pair<int, int> tira = make_pair(0,0);
    pair<int, int> melhor = make_pair(INT_MIN, INT_MAX);
    for(int i=n-1; i>=0; i--){
        if(sensores[i] == "on"){
            tira.first += intervalo[i].first;
            tira.second += intervalo[i].second;
        }
        else if(sensores[i] == "off"){
            tira.first -= intervalo[i].second;
            tira.second -= intervalo[i].first;
        }
        else{
            melhor.first = max(melhor.first, intervalo[i].first + tira.first);
            melhor.first = max(melhor.first, 0);
            melhor.second = min(melhor.second, intervalo[i].second + tira.second);
            melhor.second = max(melhor.second, 0);
        }
    }

    sai.first = melhor.first;
    sai.second = melhor.second;

    tira = make_pair(0,0);
    melhor = make_pair(INT_MIN, INT_MAX);


    for(int i = 0; i < n; i++){
        if(sensores[i] == "on"){
            tira.first += intervalo[i].first;
            tira.second += intervalo[i].second;
        }
        else if(sensores[i] == "off"){
            tira.first -= intervalo[i].second;
            tira.second -= intervalo[i].first;
        }
        else{ 
            melhor.first = max(melhor.first, intervalo[i].first - tira.second);
            melhor.first = max(melhor.first, 0);
            melhor.second = min(melhor.second, intervalo[i].second - tira.first);
            melhor.second = max(melhor.second, 0);

        }
    }
    
    cout << melhor.first << " " <<  melhor.second << endl;
    cout << sai.first << " " <<  sai.second << endl;
}