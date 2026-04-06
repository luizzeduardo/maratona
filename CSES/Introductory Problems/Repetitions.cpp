#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int maior = 1;
    int local = 1;
    for(int i=1; i< s.size(); i++){
        if(s[i] == s[i-1]){
            local++;
        }
        else{
            local = 1;
        }
        if(local > maior){
            maior = local;
        }
    }

    cout << maior << endl;
}