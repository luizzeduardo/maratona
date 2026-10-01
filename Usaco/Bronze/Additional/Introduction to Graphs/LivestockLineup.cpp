#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;

vector<string> nomes = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    map<string, int> ids;
    for(int i=0; i<8.; i++){
        ids[nomes[i]] = i;
    }


    vector<vector<int>> adj(8);

    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        string lixo;
        cin >> lixo >> lixo >> lixo >> lixo;
        string b;
        cin >> b;
        adj[ids[a]].push_back(ids[b]);
        adj[ids[b]].push_back(ids[a]);
    }

    // se o x elemento tiver 2 (limite), ele fica entre a1 x a2 lexicograficamente menor
    // se tiver apenas um podemos limitar ao lexicograficamente menor
    // se não tiver


    // basta criar componentes conexos e percorrer oo DFS dela
    vector<int>  ordem;
    vector<bool> foi(8, false);
    for(int i=0; i<8; i++){
        if(!foi[i] && adj[i].size() <= 1){
            // só ele
            foi[i] = true;
            ordem.push_back(i); 

            if(adj[i].size() == 1){
                int prev = i;
                int itera =adj[prev][0];
                while(adj[itera].size() == 2){
                    foi[itera] = true;
                    ordem.push_back(itera);

                    int a = adj[itera][0];
                    int b = adj[itera][1];
                    int temp_at;
                    if(a == prev) temp_at = b;
                    else  temp_at = a;

                    prev = itera;
                    itera = temp_at;
                }
                foi[itera] = true;
                ordem.push_back(itera);
            }
        }
    }

    for(int i: ordem) cout << nomes[i] << endl;

}