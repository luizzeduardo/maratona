#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string t, s;
        cin >> s >> t;

        bool pode = true;
        vector<char> nome(n);
        for(int i=0; i<n; i++){
            nome[i] = s[i];
        }



        for(int i=0; i<n; i++){
            bool foi = false;
            for(int j=0; j<n; j++){
                if(t[i] == nome[j] && !foi){
                    foi = true;
                    nome[j] = ' ';
                }
            }

            if(!foi){
                pode = false;
                break;
            }
        }

        if(pode){
            cout << "YES" << endl;
        }
        else if(!pode){
            cout << "NO" << endl;
        }
    }
}