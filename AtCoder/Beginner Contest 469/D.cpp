#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> finalistas;
    vector<int> quant_final(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (finalistas.count({a,b}) == 0) {  
            finalistas.insert({a,b});
            quant_final[a]++;
            quant_final[b]++;
        }
    }

    
    m = finalistas.size(); 

    // a quantidade de frequencias
    vector<int> freq(m+1, 0);      
    for (int i = 1; i <= n; i++){
        freq[quant_final[i]]++;
    }


    int maior = *max_element(quant_final.begin(), quant_final.end());


    ll resposta = 0;
    for (int i = 0; i <= maior; i++) {
        int alvo = m - i;
        if (alvo < 0 || alvo >= freq.size()) continue; // impossivelç
        if (i < alvo){
            resposta += (ll)freq[i] * freq[alvo];
        }
        else if (i == alvo){
            resposta += (ll)freq[i] * (freq[i] - 1) / 2;
        }
    }



    // apenas os que tem final em comum
    for (auto [x, y] : finalistas) { 
        int soma = quant_final[x] + quant_final[y];
        if (soma == m){
            resposta--;
        }
        if (soma == m + 1){
            resposta++;
        }   
    }

    cout << resposta << endl;
}