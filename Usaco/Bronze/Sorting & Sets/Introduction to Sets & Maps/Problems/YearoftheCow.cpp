#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){
    int n;
    cin >> n;

    //Ox, Tiger, Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat,
    map<string, int> zodiacs{{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
    
    map<string, string> cowsZodiac;
    cowsZodiac["Bessie"] = "Ox";
    map<string, int> age;

    for(int i=0; i<n; i++){
        string cow;
        cin >> cow;
        string trash;
        cin >> trash;
        cin >> trash;
        string to;
        cin >> to;
        string zodiac;
        cin >> zodiac;
        cin >> trash;
        cin >> trash;
        string comparedTo;
        cin >> comparedTo;


        cowsZodiac[cow] = zodiac;
        

        // comparar os signos
        int inicial = zodiacs[cowsZodiac[cow]];
        int conhecido = zodiacs[cowsZodiac[comparedTo]];
        
        if(to == "next"){
            if(inicial <= conhecido) inicial+=12;
        }

        else if(to == "previous"){
            if(inicial >= conhecido) inicial-=12;
        }

        age[cow] = age[comparedTo] + inicial - conhecido;


    }
    
    cout << abs(age["Bessie"] - age["Elsie"]) << endl;


}