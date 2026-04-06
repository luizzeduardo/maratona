#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        //desde de que tenha pelo menos 1 par e 1 impar na seq dá pra ordenar facilemte

        bool par = false;
        bool impar = false;

        for(int i=0; i<n; i++){
            if(a[i]%2 == 1){
                impar = true;
            }
            else{
                par = true;
            }
        }

        if(par && impar){
            sort(a.begin(), a.end());
            
        }

        for(int i=0; i<n; i++){
            cout << a[i] << " ";
        }
        cout << endl;

    }
}