#include <bits/stdc++.h>
using namespace std;

int triangulo(int a, int b, int c){
    if(a < b + c && b < a + c && c < a + b){
        return 0;
    }
    if(a == b + c || b == a + c || c == a + b){
        return 1;
    }
    else{
        return -1;
    }
}

int main(){
    vector<int> lados(4);
    cin >> lados[0] >> lados[1] >> lados[2] >> lados[3];

    //0 = triangulo nomal, 1= segmento, -1 = impossivel
    vector<int> tipo(4, -1);
    
    tipo[0] = triangulo(lados[0], lados[1], lados[2]);
    tipo[2] = triangulo(lados[0], lados[1], lados[3]);
    tipo[1] = triangulo(lados[0], lados[2], lados[3]);
    tipo[3] = triangulo(lados[1], lados[2], lados[3]);

    

    bool seg = false;
    for(int i=0; i<4 ;i++){
        if(tipo[i] == 0){
            cout << "TRIANGLE" << endl;
            return 0;
        }
        if(tipo[i] == 1){
            seg = true;
        }
    }

    if(seg){
        cout << "SEGMENT" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}