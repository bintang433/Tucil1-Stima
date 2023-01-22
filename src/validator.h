#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool validator(string s, vector<float> &input){
    string temp;
    stringstream stream(s);
    bool valid = true;
    string str[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; 
    int len = sizeof(str)/sizeof(str[0]);
    long long dist;

    while(getline(stream, temp, ' ')){
        auto idx = find(str, str + len, temp);
        if (idx != end(str)){
            dist = distance(str, idx) + 1;
            input.push_back(float(dist));
        }else{
            valid = false;
        }
    }
    
    valid = input.size()!=4 ? false : valid; 
    return valid;

}

#endif