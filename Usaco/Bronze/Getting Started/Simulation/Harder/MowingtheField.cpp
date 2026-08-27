#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n;
    cin >> n;
    set<int> colisoes;

    vector<int> tempo;
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(0,0));
    tempo.push_back(0);


    for(int i=0; i<n; i++){
        string dir;
        cin >> dir;
        int mov;
        cin >> mov;

        // move
        if(dir == "N"){
            for(int j=0; j<mov; j++){
                int agr = tempo.back();
                tempo.push_back(agr+1);

                int x = pos.back().first;
                int y = pos.back().second+1;
                pair<int, int> novo = make_pair(x,y);
                auto it = find(pos.rbegin(), pos.rend(), novo);
                if(it != pos.rend()){
                    int index = distance(it, pos.rend()) -1;
                    int total = tempo.back() - tempo[index];
                    colisoes.insert(total);
                }
                pos.push_back(novo);

                
            }
        }
        else if(dir == "S"){
            for(int j=0; j<mov; j++){
                int agr = tempo.back();
                tempo.push_back(agr+1);

                int x = pos.back().first;
                int y = pos.back().second-1;
                pair<int, int> novo = make_pair(x,y);
                auto it = find(pos.rbegin(), pos.rend(), novo);
                if(it != pos.rend()){
                    int index = distance(it, pos.rend()) -1;
                    int total = tempo.back() - tempo[index];
                    colisoes.insert(total);
                }
                pos.push_back(novo);


            }        
        }
        else if(dir == "W"){
            for(int j=0; j<mov; j++){
                int agr = tempo.back();
                tempo.push_back(agr+1);

                int x = pos.back().first-1;
                int y = pos.back().second;
                pair<int, int> novo = make_pair(x,y);
                auto it = find(pos.rbegin(), pos.rend(), novo);
                if(it != pos.rend()){
                    int index = distance(it, pos.rend()) -1;
                    int total = tempo.back() - tempo[index];
                    colisoes.insert(total);
                }
                pos.push_back(novo);


            }        
        }
        else if(dir == "E"){
            for(int j=0; j<mov; j++){
                int agr = tempo.back();
                tempo.push_back(agr+1);

                int x = pos.back().first+1;
                int y = pos.back().second;
                pair<int, int> novo = make_pair(x,y);
                auto it = find(pos.rbegin(), pos.rend(), novo);
                if(it != pos.rend()){
                    int index = distance(it, pos.rend()) -1;
                    int total = tempo.back() - tempo[index];
                    colisoes.insert(total);
                }
                pos.push_back(novo);


            }        
        }




    }
    if(colisoes.empty()){
        cout << -1 << endl;
    }
    else{
        for(int resposta : colisoes){
            cout << resposta << endl;
            return 0;
        }
    }


}