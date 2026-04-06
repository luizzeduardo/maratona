#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    multiset<int> trees;
    while(q--){
        int tipo, h;
        cin >> tipo >> h;
        if(tipo == 1){
            trees.insert(h);
        }
        else if(tipo == 2){
            auto lim = trees.upper_bound(h);
            trees.erase(trees.begin(), lim);
        }

        cout << trees.size() << endl;
    }
}