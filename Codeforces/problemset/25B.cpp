#include <bits/stdc++.h>
using namespace std;

int main(){

    int tam;
    cin >> tam;
    string num;
    cin >> num;


    bool tres = false;
    if(tam%2 == 1){
        tres = true;
    }

    int aux = 0;
    for(int i=0; i<num.length(); i++){
        if(tres){
            if(aux==3){
                cout << "-";
                aux = 0; 
                tres = false;
            }
        }
        else{
            if(aux==2){
                cout << "-";
                aux = 0;
            }
        }
        cout << num[i];
        aux++;
    }
    cout << endl;
}