#ifndef PERMUTE_H
#define PERMUTE_H

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

void permute(vector<vector<float>>* prm, vector<float> a, int l, int r)
{
	// Base case
	if (l == r){
        if (!findVec(*prm, a)){
			prm->push_back(a);
		}
    }
	else {
		// Permutations made
		for (int i = l; i <= r; i++) {

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(prm, a, l + 1, r);

			// backtrack
			swap(a[l], a[i]);
		}
	}
}

void repetitionPermutation(vector<vector<string>>* repPrm, string prefix, int n){
	string prm;
	vector<string> prmVec (4, "");
	string op[4] = {"+", "-", "*", "/"};
	int len = 4;

	if (n == 1){
		for (int i = 0; i < len; i++){
			prm = prefix + op[i];
			for (int j = 0; j < prm.length(); j++){
				string temp(1, prm[j]);
				prmVec[j] = temp;
			}
			repPrm->push_back(prmVec);
		}
	}else{
		for (int i = 0; i < len; i++){
			repetitionPermutation(repPrm, prefix + op[i], n - 1);
		}
	}

}

#endif