#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> atual(m+1, 0);
    vector<int> proximo(m+1, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        atual[a]++;
        proximo[b]++;
    }
    
    for (int j = 1; j <= m; j++) {
        cout << proximo[j] - atual[j] << endl;
    }
}