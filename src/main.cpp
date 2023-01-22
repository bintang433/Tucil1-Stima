#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "permutation.h"
#include "validator.h"
#include "selector.h"

/*int main(){
    char card[4];
    cin >> card[0] >> card[1] >> card[2] >> card[3];
    cout << card;
    return 0;
}*/

int main()
{
	vector<vector<string>> result;
    vector<float> intInput;
    vector<vector<float>> floatPrm;
    string strInput;
    vector<vector<string>> opPrm;

    repetitionPermutation(&opPrm, "", 3);

    getline (cin, strInput);
    bool valid = validator(strInput, intInput);   
    if (valid){
        permute(&floatPrm, intInput, 0, intInput.size()-1);
        result24(opPrm, floatPrm, &result);
        cout << result.size() << endl;
        for (vector<string> vec : result){
            for (string s : vec){
                cout << s;
            }
            cout << "\n";
        }
    }else{
        cout << "Input tidak valid" << endl;
    }
	return 0;
}
