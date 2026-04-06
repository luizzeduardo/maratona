#include <bits/stdc++.h>
using namespace std;

int rest(int num){

}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int q=0;

        //fazer uma arvore binária para cada caso (interessante) de div de n
        // de forma que cada no da arvore é o valor total acumulado 

        while(true){
            if(k == n){
                cout << q << endl;
                break;
            }
            if(k > n){
                cout << -1 << endl;
                break;
            }
            else{
                
            }
            q++;
        }
        
        vector<int> divs(n+1, 0);
        


    }

}