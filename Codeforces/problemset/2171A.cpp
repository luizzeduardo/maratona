#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //vacas 4
        //galinhas 2

        //2 == 1
        //3 == 0

        if(n%2 == 1){
            cout << 0 << endl;
        }
        else{
            int num = 1;
            num += n/4;
            cout << num << endl;
        }

    }
}