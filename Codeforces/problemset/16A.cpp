#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<char>> sqr(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> sqr[i][j];
        }
    }
    bool striped = true;
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            if(sqr[i][j] != sqr[i][j-1]){
                striped = false;
                break;
            }
        }
        if(!striped){
            break;
        }
    }

    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++){
            if(sqr[i][j] == sqr[i-1][j]){
                striped= false;
                break;
            }
        }
        if(!striped){
            break;
        }
    }

    if(striped){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}