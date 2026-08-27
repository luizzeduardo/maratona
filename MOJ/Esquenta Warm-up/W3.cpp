#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> filho;
vector<int> subarvore; 


void dfs(int u){
    subarvore[u] = 0;
    for(int c: filho[u]){
        dfs(c);
        subarvore[u] += subarvore[c] + 1;
    }
}

int main(){
    int n;
    cin >> n;

    filho.assign(n+1, {});
    subarvore.assign(n+1, 0);

    for(int i=2; i<=n; i++){
        int chefe; 
        cin >> chefe;
        filho[chefe].push_back(i);
    }

    dfs(1);
    

    for(int i=1; i<=n; i++){
        cout <<subarvore[i] << endl;
    }
    

}