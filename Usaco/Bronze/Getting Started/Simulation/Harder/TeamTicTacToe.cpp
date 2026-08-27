#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	
	vector<vector<string>> ppt(3, vector<string>(3));

	
	for(int i=0; i<3; i++){
        string a;
        cin >> a;
		for(int j=0; j<3; j++){
			ppt[i][j] = a[j];
		}
	}


	set<string> letras;
    set<string> individual;
    set<pair<string, string>> dupla;

	//linha
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			letras.insert(ppt[i][j]);
		}
		
		if(letras.size() == 1){
            for(string vencedor : letras){
                individual.insert(vencedor);
            }
		}
		else if(letras.size() == 2){
            vector<string> par;
            for(string vencedor : letras){
                par.push_back(vencedor);
            }		
            pair<string, string> dois = make_pair(par[0], par[1]);
            dupla.insert(dois);

        }
        
        letras.clear();

	}
	


	// colunas
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			letras.insert(ppt[j][i]);
		}
		
		if(letras.size() == 1){
            for(string vencedor : letras){
                individual.insert(vencedor);
            }
		}
		else if(letras.size() == 2){
            vector<string> par;
            for(string vencedor : letras){
                par.push_back(vencedor);
            }		
            pair<string, string> dois = make_pair(par[0], par[1]);
            dupla.insert(dois);		
        }

        letras.clear();

	}
	


    // diagonal principal
    for(int j=0; j<3; j++){
        letras.insert(ppt[j][j]);
    }
    
		if(letras.size() == 1){
            for(string vencedor : letras){
                individual.insert(vencedor);
            }
		}
		else if(letras.size() == 2){
            vector<string> par;
            for(string vencedor : letras){
                par.push_back(vencedor);
            }		
            pair<string, string> dois = make_pair(par[0], par[1]);
            dupla.insert(dois);		
        }
    
    letras.clear();

    
    // diagonal secundaria
    for(int j=2; j>=0; j--){
        letras.insert(ppt[j][2-j]);
    }
    
		if(letras.size() == 1){
            for(string vencedor : letras){
                individual.insert(vencedor);
            }
		}
		else if(letras.size() == 2){
            vector<string> par;
            for(string vencedor : letras){
                par.push_back(vencedor);
            }		
            pair<string, string> dois = make_pair(par[0], par[1]);
            dupla.insert(dois);		
        }
    

    int um = individual.size();
    int dois = dupla.size();
    
    cout << um << endl;
    cout << dois << endl;

}