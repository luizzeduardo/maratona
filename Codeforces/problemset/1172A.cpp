#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    vector<int> pos(n + 1, -1);// -1 na mão
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != 0) {
            pos[b[i]] = i;
        }
    }
    
    int pos1 = pos[1];
    
    if (pos1 != -1) {
        bool seq = true;
        for (int i = pos1; i < n; i++) {
            if (b[i] != i - pos1 + 1) {
                seq = false;
                break;
            }
        }
        
        if (seq) {

            bool todos_na_mao = true;
            for (int i = 1; i < pos1; i++) {
                if (pos[i] != -1) { 
                    todos_na_mao = false;
                    break;
                }
            }
            
            if (todos_na_mao) {
                cout << pos1 << endl;  // pos1 é 0-indexado, então número de ops = pos1
                return 0;
            }
        }
    }
    
    // A ideia: encontrar o maior tempo necessário para cada carta
    
    int ans = 0;
    
    // Primeiro, encontrar a posição mais atrasada na pilha
    for (int i = 1; i <= n; i++) {
        if (pos[i] != -1) {
            // Carta i está na pilha na posição pos[i]
            // Ela precisa de pos[i] + 1 operações para chegar ao topo
            // e mais n-i operações para esperar as cartas maiores
            ans = max(ans, pos[i] + 1 + (n - i));
        } else {
            // Carta i está na mão
            // Podemos colocá-la a qualquer momento, mas precisa esperar
            // as cartas menores (i-1, i-2, ...) serem colocadas
            ans = max(ans, n - i + 1);
        }
    }
    
    // Ajuste fino: se a resposta for muito grande, podemos reduzir
    // porque podemos começar a colocar cartas antes
    if (pos1 != -1) {
        // Se 1 está na pilha, podemos começar a colocar cartas antes
        ans = min(ans, n + pos1 + 1);
    }
    
    cout << ans << endl;
    
    return 0;
}