#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    // calcular primeiro as potencias de 2 
    // depois fazer as combinações possiveis
    // depois voltar praint e ordenar


    // preciso saber o tam de cada num rápido
    vector<string> pot;
    ll p = 1;
    while(p< 1000000000){ //10^9
        pot.push_back(to_string(p));
        p *= 2;
    }

    set<string> good_set;
    queue<string> q;

    for (string& p : pot) {
        good_set.insert(p);
        q.push(p);
    }

    // gerar todas as concatenacoes
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        // Tentar concatenar cada potência no final
        for (string& p : pot) {
            string new_str = current + p;
            
            // Verificar se o número é <= 10^9
            if (new_str.length() <= 10) {
                ll num = stoll(new_str);
                if (num <= 1e9 && good_set.find(new_str) == good_set.end()) {
                    good_set.insert(new_str);
                    q.push(new_str);
                }
            }
        }
    }

    vector<ll> good_numbers;
    for (string s : good_set) {
        good_numbers.push_back(stoll(s));
    }
    sort(good_numbers.begin(), good_numbers.end());

    cout << good_numbers[n-1] << endl;


    //1 2 4 8  (11 12 14)  16  (18 21 22 24 28)  32 64 (os de 2 dig + 1 dig) 128 256
}


