#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool validator(string s, vector<float>* input){
    string temp;
    long long dist;

    stringstream stream(s);
    string str[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; 
    int len = sizeof(str)/sizeof(str[0]);
    bool valid = true;

    while(getline(stream, temp, ' ')){              //ambil setiap string yang dipisahkan spasi
        auto idx = find(str, str + len, temp);      //cari dalam array str
        if (idx != end(str)){                       //jika ada, indeks + 1 dimasukan ke vektor input
            dist = distance(str, idx) + 1;
            input->push_back(float(dist));
        }else{                                      //jika tidak, input tidakk valid
            valid = false;
        }
    }
    
    valid = input->size()!=4 ? false : valid;       //jika input != 4, maka input tidak valid
    return valid;

}

#endif