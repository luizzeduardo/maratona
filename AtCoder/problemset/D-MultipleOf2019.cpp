#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int pow =1; 

    vector<int> resto(s.size()+1);

    int pow10 = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        int digito = s[i] - '0';
        resto[i] = (digito * pow10 + resto[i + 1]) % 2019;
        pow10 = (pow10 * 10) % 2019;
    }

    vector<int> freq(2019, 0);
    for(int i=0; i<=s.size(); i++){
        freq[resto[i]]++;
    }

    int sub2019 = 0;

    //numeoros trinagulares -> resposta = n(n+1)/2
    for(int i=0; i<2019; i++){
        if(freq[i] == 0 || freq[i] == 1){
            continue;
        }
        else{
            int resp = freq[i];
            sub2019 += resp * (resp-1)/2;
        }
        
    }

    cout << sub2019 << endl;

}