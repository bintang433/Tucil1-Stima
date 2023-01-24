#ifndef UTILITY_H
#define UTILITY_H

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void createFile (string fileName, vector<vector<string>> result){
    ofstream textFile("../test/"+fileName+".txt");

    for (vector<string> vec : result){
        for (string s : vec){
            textFile << s;
        }
        textFile << "\n";
    }
    textFile.close();
}

vector<string> randomizer(){
    vector<string> vec;
    int idx;

    string str[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    srand(time(NULL));
    for (int i = 0; i < 4; i++){
        idx = rand() % 13;
        vec.push_back(str[idx]);
    }
    return vec; 
}

bool floatEq(float x, float y, float epsilon = 0.01f){
    if(fabs(x - y) < epsilon){
      return true;
    }
    return false;

}

void displayVector(vector<float> vec){
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << ' ';
	}
	cout << "\n";
}

void displayStrVector(vector<string> vec){
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i];
	}
	cout << "\n";
}

bool findVec(vector<vector<float>> prm, vector<float> src){
	bool found = false;
	auto idx = find(prm.begin(), prm.end(), src);
	if (idx!=prm.end()){
		found = true;
	}
	return found;
}

#endif