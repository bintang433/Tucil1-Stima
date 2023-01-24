#ifndef PERMUTATION_H
#define PERMUTATION_H

#include "utility.h"
using namespace std;



void permute(vector<vector<float>>* floatPrm, vector<float> flt, int l, int r){
	if (l == r){									//l adalah elemen yang ditahan / posisi tidak diubah. dimulai dari 0
        if (!findVec(*floatPrm, flt)){				//r adalah panjang elemen-1. jika l==r, tidak ada elemen lain yang perlu
			floatPrm->push_back(flt);					//diacak. langsung di push ke floatPrm
		}
    }else {
		for (int i = l; i <= r; i++) {				//masing-masing elemen ditahan, elemen lain dipermutasikan
			swap(flt[l], flt[i]);
			permute(floatPrm, flt, l + 1, r);
			swap(flt[l], flt[i]);
		}
	}
}

void repetitionPermutation(vector<vector<string>>* repPrm, string prefix, int n){
	string prm;
	vector<string> prmVec (4, "");
	
	string op[4] = {"+", "-", "*", "/"};
	int len = 4;

	if (n == 1){													//prefix adalah elemen yang ditahan
		for (int i = 0; i < len; i++){								//n adalah banyak elemen yang perlu dipermutasikan
			prm = prefix + op[i];									//jika n==1, elemen tersebut adalah masing masing elemen operator
			for (int j = 0; j < prm.length(); j++){
				string temp(1, prm[j]);
				prmVec[j] = temp;
			}
			repPrm->push_back(prmVec);
		}
	}else{
		for (int i = 0; i < len; i++){
			repetitionPermutation(repPrm, prefix + op[i], n - 1);	//setiap elemen ditambahkan menjadi prefix baru,
		}															//elemen yang dipermutasikan berkurang.
	}
}

#endif