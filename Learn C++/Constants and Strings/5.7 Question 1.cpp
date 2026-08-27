#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Enter you full name: ";
    string nome;
    getline(cin, nome);
    int idade;
    cout << "Now your age: ";
    cin >> idade;
    cout << "Your age + length name is: " << idade + nome.length() << endl;
}