#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int>caminho(n);
    vector<int> limite(n);
    vector<int>rota(m);
    vector<int> vel(m);


    for(int i=0;i<n; i++){
        cin >> caminho[i] >> limite[i];
    }

    for(int i=0;i<m; i++){
        cin >> rota[i] >> vel[i];
    }

    int maior = 0;
    int percorrido = 0;
    int percurso = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            percurso+= caminho[j];
            // entre dois
            if(percurso - caminho[j] <= percorrido && percurso > percorrido){
                if(limite[j] < vel[i]){
                    int passou = vel[i] - limite[j];
                    if(maior < passou){
                        maior = passou;
                    }
                }

            }
            //percorrido contém um caminho inteiro limite
            else if(percorrido <= percurso-caminho[j] && percorrido+rota[i] >= percurso){
                if(limite[j] < vel[i]){
                    int passou = vel[i] - limite[j];
                    if(maior < passou){
                        maior = passou;
                    }
                }
            }

            else if(percorrido < percurso - caminho[j] && percorrido+rota[i] < percurso && percorrido + rota[i] > percurso - caminho[j] ){
                if(limite[j] < vel[i]){
                    int passou = vel[i] - limite[j];
                    if(maior < passou) {
                        maior = passou;
                    }
                }
            }
        }
        percorrido += rota[i];
        percurso = 0;

    }

    cout << maior << endl;


}