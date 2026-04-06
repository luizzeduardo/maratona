#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//quanto menor o prefix ou sufix, potencialmente menor é o MEX -> 
//é impossivel que um prefix maior tenha um MEX menor, no minimo o mesmo de antes
//é impossivel um sufix menor ter um MEX maior, no minimo o mesmo

//If there are no zeros in a, it's impossible. If there's exactly one zero, it's always possible

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> count(n+1,0);
        for(int i=0; i<n; i++){
            cin >> a[i];
            count[a[i]]++;
        }

        //se tiver APENAS 1 zero já passa, mais de um precisa de desempate no proximo (exatamente um tbm progressivamente)

        if(count[0] == 0){
            cout << "NO" << endl;
        }
        else if(count[0] == 1){
            cout << "YES" << endl;
        }
        else if(count[1] > 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }
}