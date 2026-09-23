#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, f;
    cin >> n >> f;
    string s;
    cin >> s;

    map<string, vector<int>> moos;
    for(int i=2; i<n; i++){
        if(s[i] == s[i-1] && s[i] != s[i-2]){
            string caso = "";
            caso += s[i-2];
            caso += s[i-1];
            caso += s[i];
            moos[caso].push_back(i-2);
        }
    }

    set<string> validos;

    if(f==1){
        for(int i=2; i<n; i++){
            if(s[i-1] == s[i]){
                for(int j=0; j<26; j++){
                    string valido = "";
                    valido += 'a' + j;
                    if(valido[0] == s[i]) continue;
                    valido += s[i-1];
                    valido += s[i];
                    validos.insert(valido);
                }
            }
            if(s[i-2] != s[i]) validos.insert(string{s[i-2], s[i], s[i]});
            if(s[i-2] != s[i-1]) validos.insert(string{s[i-2], s[i-1], s[i-1]});
        }
    }
    
    else for(auto[moo, pos]: moos){
        //cout << moo << endl;
        if(pos.size() == f-1){
            for(int i=2; i<n; i++){
                int igual = 0;
                for(int poses: pos){
                    //cout << poses << endl;
                    if(poses >= i-4 && poses <= i) i = poses + 5;
                }

                if(i >= n) break;

                if(s[i-2] == moo[0]) igual++; 
                if(s[i-1] == moo[1]) igual++; 
                if(s[i] == moo[2])   igual++; 

                if(igual == 2){
                    validos.insert(moo);
                    break;
                }
            }   
        }
        else if (pos.size() >= f){
            validos.insert(moo);
        }
    }

    cout << validos.size() << endl;
    for(string valido: validos) cout << valido << endl;

}

