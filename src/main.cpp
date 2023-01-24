#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include "permutation.h"
#include "selector.h"
#include "validator.h"
#include "utility.h"
using namespace std;
using namespace std::chrono;

int main(){
	vector<vector<string>> result;
    vector<float> floatInput;
    vector<string> strVec;
    vector<vector<float>> floatPrm;
    vector<vector<string>> opPrm;
    int inOpt;
    char saveOpt;
    string fileName;
    string strInput;

    repetitionPermutation(&opPrm, "", 3);               //Permutasi operator dengan pengulangan. Hanya perlu
    int cont = 1;                                       //dilakukan sekali

    while (cont==1){
        floatInput.clear();                               //Hapus isi vektor setiap mencari solusi
        result.clear();
        strVec.clear();
        floatPrm.clear();

        cout << "Pilih opsi input :\n";                 //Opsi input
        cout << "1. Input dari keyboard\n";
        cout << "2. Input angka random\n";
        cin >> inOpt;

        if (inOpt==1){                                  //Input manual dari keyboard, format 4 buah "kartu" A, 2, .., K
            cout << "Input 4 card numbers :";          //dipisahkan spasi
            cin >> ws;
            getline (cin, strInput);
        }else if (inOpt==2){
            string temp = "";                           //Ambil 4 kartu random (bisa berulang) dari fungsi randomizer
            strVec = randomizer();                      //hasil berupa vektor of string
            for (int i = 0; i < 4; i++){                //Ubah vektor menjadi format string seperti pada input manual
                temp += strVec[i];
                if (i!=3){
                    temp += " ";
                }
            }
            strInput = temp;
            cout << strInput << endl;           
        }

        bool valid = validator(strInput, &floatInput);            //Validasi input, harus 4 "kartu" dengan format yang benar
        if (valid){
            auto begin = high_resolution_clock::now();          //Ambil waktu mulai algoritma untuk menghitung execution time

            permute(&floatPrm, floatInput, 0, floatInput.size()-1); //Permutasi urutan kartu, disimpan dalam vector yang berisi vector of float
            result24(opPrm, floatPrm, &result);                 //Hitung hasil permutasi dengan semua kemungkinan operasi.
                                                                //Jika hasi operasi == 24, masuk ke vector result
            auto end = high_resolution_clock::now();            //Selesai menghitung waktu algoritma. hasil dalam satuan detik
            auto duration = duration_cast<microseconds>(end - begin).count()/1000000.0;
            
            if (result.size()>0){                               //Output hasil jika ada, konfirmasi simpan jawaban ke txt file
                cout << result.size() << " solutions found\n";
                for (vector<string> vec : result){
                    displayStrVector(vec);
                }
                cout << "Execution time : " << duration << " seconds\n";
                cout << "Save answer as txt file? (y/n) : ";
                cin >> saveOpt;
                if (saveOpt=='y'){
                    cout << "Input file name :";
                    cin >> fileName;
                    createFile(fileName, result);
                }
            }else{
                cout << "No soltion found\n";
                cout << "Execution time : " << duration << " seconds\n";
            }
        }else{
            cout << "Input tidak valid\n";
        }
        cout << "Continue/Exit? (1/0) : ";
        cin >> cont;
    }
	return 0;
}
