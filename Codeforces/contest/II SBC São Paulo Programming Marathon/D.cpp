#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++) cout << " ";
    for(int i=0; i<n; i++) cout <<'-';
    cout << endl; // cabecça

    for(int i=1; i<n-1; i++) {


        cout << endl;
    }



    //meio
    cout << "/";
    for(int i=0; i<n-1; i++) cout <<'-';// n vezes
    for(int i=0; i<n; i++) cout << ' ';
    cout << "\\";
    for(int i=0; i<n; i++) cout << '-';// n+1 vezes
    cout << endl;



    for(int i=0; i<n-1; i++){
        for(int j=n-i+1; j<n*2+1; j++) cout << " ";
        cout << '\\';
        for(int j=0; j<(2*n+1)- i*2; j++) cout << " ";// (n+1) + 2*(n-i)
        cout << "/";
        cout << endl;
    }

    //finalzin
    for(int i=0; i<n+1; i++)cout << ' ';
    cout << "\\";
    for(int i=0; i<n; i++) cout << '-';
    cout << "/";
    cout << endl; 


    


}