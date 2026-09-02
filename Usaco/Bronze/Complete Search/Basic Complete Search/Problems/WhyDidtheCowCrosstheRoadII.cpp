#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s;
    cin >> s;
    
    set<char> visited;
    int n = s.size();
    int total = 0;



    for(int i=0;i<n-1; i++){
        if(!visited.count(s[i])){
            vector<int> quant(26, 0);
            for(int j=i+1; s[j] != s[i]; j++){
                if(!visited.count(s[j])){
                    quant[s[j] -'A']++;
                }
            }
            for(int j=0; j<26; j++){
                if(quant[j] == 1) total++;
            }
            visited.insert(s[i]);
        }
    }

    cout << total << endl;

}