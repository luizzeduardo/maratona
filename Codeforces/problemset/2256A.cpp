#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t;
    cin >> t;
    while(t--){
        int maior = INT_MIN;
        int menor = INT_MAX;
        int soma = 0;
        vector<int> nums(3);
        cin >> nums[0]; 
        cin >> nums[1]; 
        cin >> nums[2]; 

        for(int i=0; i<3; i++){
            if(maior < nums[i]){
                maior = nums[i];
            }
            if(menor > nums[i]){
                menor = nums[i];
            }
            soma += nums[i];
        }

        soma -= maior;
        if(soma < maior){
            maior = soma;
        }

        cout << maior - menor << endl;



        // minimizar o range é sempre substituir o maior elemento pela soma dos menores se a soma for menor, caso contrario nada fazer


        
    }
}
