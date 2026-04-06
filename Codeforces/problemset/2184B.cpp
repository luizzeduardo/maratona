#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int s, k, m;
        cin >> s >> k >> m;


        if(s == k){
            if(s > m){
                cout << s - m << endl;
            }
            else if(s == m){
                cout << s << endl;
            }
            else{
                cout << s - m%s << endl;
            }
        }

        else if(k > s){

            int rest = m%k;
            
            if(m <= s){
                cout << s-m << endl; 
            }
            else if(m < k){
                cout << 0 << endl;
            }
            else if(m >= k){
                int rest = m%k;
                if(rest <= s){
                    cout << s-rest << endl;
                }
                else{
                    cout << 0 << endl;
                }
            }    
        }

        else if(k <= s){

            int quant = m/k;
            if(m<k){
                cout << s-m << endl;
            }
            else if(quant%2 == 0){
                cout << s - m%k << endl;
            }
            else if(quant%2 == 1){
                cout << k - m%k << endl;
            }
        }

        //se s/m par = s - k - s%m
            //se impar = k - s%m
    }
}