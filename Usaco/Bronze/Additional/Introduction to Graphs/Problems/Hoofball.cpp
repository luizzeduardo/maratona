#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    // 1 -> 7
    // 2 -> 1
    // 3 -> 3
    // 4 -> 11
    // 5 -> 4
    sort(a.begin(), a.end());
    vector<int> passa(n);
    passa[0] = 1;
    passa[n-1] = n-2;
    for(int i=1; i<n-1; i++){
        if(a[i] - a[i-1] <= a[i+1] - a[i]){
            passa[i] = i-1;
        }
        else passa[i] = i+1;
    }

    vector<int> recebe(n, 0);
    for(int i=0; i<n; i++) recebe[passa[i]]++;
    
    int bolas = 0;
    for(int i = 0; i<n; i++){
        // o proximo
        int j = passa[i];
        if(recebe[i] == 0) bolas++; // ponto final
        if(i < j && passa[j] == i && recebe[i] == 1 && recebe[j] == 1) bolas++;
    }
    cout << bolas << endl;
}