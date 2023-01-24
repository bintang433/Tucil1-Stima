#ifndef SELECTOR_H
#define SELECTOR_H

#include "permutation.h"

using namespace std;

float evaluator(vector<string> eq, vector<float> val, int opt){
    float retVal;
    float tempVal;

    map<string, int> op;                    //pengkodean operator agar bisa menggunakan switch
    op["+"] = 1;
    op["-"] = 2;
    op["*"] = 3;
    op["/"] = 4;

// 1. a O b O c O d                         //opt diisi dengan bentuk persamaan sesuai urutan.
// 2. (( a O b ) O c ) O d                  
// 3. ( a O ( b O c )) O d
// 4. a O (( b O c ) O d )
// 5. a O ( b O ( c O d ))
// 6. ( a O b ) O ( c O d )

    switch (opt){                           //Algoritma untuk mengevaluasi string persamaan sesuai bentuk persamaannya
        case 2:
            switch (op[eq[2]]){
                case 1:
                    retVal = val[0] + val[1];
                    break;
                case 2:
                    retVal = val[0] - val[1];
                    break;
                case 3:
                    retVal = val[0] * val[1];
                    break;
                case 4:
                    retVal = val[0] / val[1];
                    break;
            }
            switch (op[eq[5]]){
                case 1:
                    retVal += val[2];
                    break;
                case 2:
                    retVal -= val[2];
                    break;
                case 3:
                    retVal *= val[2];
                    break;
                case 4:
                    retVal /= val[2];
                    break;
            }
            switch (op[eq[8]]){
                case 1:
                    retVal += val[3];
                    break;
                case 2:
                    retVal -= val[3];
                    break;
                case 3:
                    retVal *= val[3];
                    break;
                case 4:
                    retVal /= val[3];
                    break;
            }
            break;
        case 3:
            switch (op[eq[5]]){
                case 1:
                    retVal = val[1] + val[2];
                    break;
                case 2:
                    retVal = val[1] - val[2];
                    break;
                case 3:
                    retVal = val[1] * val[2];
                    break;
                case 4:
                    retVal = val[1] / val[2];
                    break;
            }
            switch (op[eq[2]]){
                case 1:
                    retVal = val[0] + retVal;
                    break;
                case 2:
                    retVal = val[0] - retVal;
                    break;
                case 3:
                    retVal = val[0] * retVal;
                    break;
                case 4:
                    retVal = val[0] / retVal;
                    break;
            }
            switch (op[eq[8]]){
                case 1:
                    retVal += val[3];
                    break;
                case 2:
                    retVal -= val[3];
                    break;
                case 3:
                    retVal *= val[3];
                    break;
                case 4:
                    retVal /= val[3];
                    break;
            }
            break;
        case 4:
            switch (op[eq[4]]){
                case 1:
                    retVal = val[1] + val[2];
                    break;
                case 2:
                    retVal = val[1] - val[2];
                    break;
                case 3:
                    retVal = val[1] * val[2];
                    break;
                case 4:
                    retVal = val[1] / val[2];
                    break;
            }
            switch (op[eq[7]]){
                case 1:
                    retVal += val[3];
                    break;
                case 2:
                    retVal -= val[3];
                    break;
                case 3:
                    retVal *= val[3];
                    break;
                case 4:
                    retVal /= val[3];
                    break;
            }
            switch (op[eq[1]]){
                case 1:
                    retVal = val[0] + retVal;
                    break;
                case 2:
                    retVal = val[0] - retVal;
                    break;
                case 3:
                    retVal = val[0] * retVal;
                    break;
                case 4:
                    retVal = val[0] / retVal;
                    break;
            }
            break;
        case 5:
            switch (op[eq[7]]){
                case 1:
                    retVal = val[2] + val[3];
                    break;
                case 2:
                    retVal = val[2] - val[3];
                    break;
                case 3:
                    retVal = val[2] * val[3];
                    break;
                case 4:
                    retVal = val[2] / val[3];
                    break;
            }
            switch (op[eq[4]]){
                case 1:
                    retVal = val[1] + retVal;
                    break;
                case 2:
                    retVal = val[1] - retVal;
                    break;
                case 3:
                    retVal = val[1] * retVal;
                    break;
                case 4:
                    retVal = val[1] / retVal;
                    break;
            }
            switch (op[eq[1]]){
                case 1:
                    retVal = val[0] + retVal;
                    break;
                case 2:
                    retVal = val[0] - retVal;
                    break;
                case 3:
                    retVal = val[0] * retVal;
                    break;
                case 4:
                    retVal = val[0] / retVal;
                    break;
            }
            break;
        case 6:
            switch (op[eq[2]]){
                case 1:
                    retVal = val[0] + val[1];
                    break;
                case 2:
                    retVal = val[0] - val[1];
                    break;
                case 3:
                    retVal = val[0] * val[1];
                    break;
                case 4:
                    retVal = val[0] / val[1];
                    break;
            }
            switch (op[eq[8]]){
                case 1:
                    tempVal = val[2] + val[3];
                    break;
                case 2:
                    tempVal = val[2] - val[3];
                    break;
                case 3:
                    tempVal = val[2] * val[3];
                    break;
                case 4:
                    tempVal = val[2] / val[3];
                    break;
            }
            switch (op[eq[5]]){
                case 1:
                    retVal += tempVal;
                    break;
                case 2:
                    retVal -= tempVal;
                    break;
                case 3:
                    retVal *= tempVal;
                    break;
                case 4:
                    retVal /= tempVal;
                    break;
            }
            break;
        default :                           //default ketika opt == 1, persamaan tanpa tanda kurung.
            if (op[eq[1]]==3 || op[eq[1]]==4 || op[eq[3]]==3 ||
                op[eq[3]]==4 || op[eq[5]]==3 || op[eq[5]]==4){     
                if (op[eq[1]]==3 || op[eq[1]]==4){
                    if (op[eq[1]]==3){
                        retVal = val[0]*val[1];
                    }else if (op[eq[1]]==4){
                        retVal = val[0]/val[1];
                    }
                    if (op[eq[3]]==3 || op[eq[3]]==4){
                        if (op[eq[3]]==3){
                            retVal *= val[2];
                        }else if (op[eq[3]]==4){
                            retVal /= val[2];
                        }
                        if (op[eq[5]]==1){
                            retVal += val[3];
                        }else if (op[eq[5]]==2){
                            retVal -= val[3];
                        }else if (op[eq[5]]==3){
                            retVal *= val[3];
                        }else if (op[eq[5]]==4){
                            retVal /= val[3];
                        }
                    }else{
                        if (op[eq[5]]==1){
                            tempVal = val[2]+val[3];
                        }else if (op[eq[5]]==2){
                            tempVal = val[2]-val[3];
                        }else if (op[eq[5]]==3){
                            tempVal = val[2]*val[3];
                        }else if (op[eq[5]]==4){
                            tempVal = val[2]/val[3];
                        }
                        if (op[eq[3]]==1){
                            retVal += tempVal;
                        }else if (op[eq[3]]==2){
                            retVal -= tempVal;
                        }else if (op[eq[3]]==3){
                            retVal *= tempVal;
                        }else if (op[eq[3]]==4){
                            retVal /= tempVal;
                        }
                    }
                }else if (op[eq[3]]==3 || op[eq[3]]==4){
                    if (op[eq[3]]==3){
                        retVal = val[1]*val[2];
                    }else if (op[eq[3]]==4){
                        retVal = val[1]/val[2];
                    }
                    if (op[eq[5]]==1){
                        retVal += val[3];
                    }else if (op[eq[5]]==2){
                        retVal -= val[3];
                    }else if (op[eq[5]]==3){
                        retVal *= val[3];
                    }else if (op[eq[5]]==4){
                        retVal /= val[3];
                    }
                    if (op[eq[1]]==1){
                        retVal = val[0]+retVal;
                    }else if (op[eq[1]]==2){
                        retVal = val[0]-retVal;
                    }else if (op[eq[1]]==3){
                        retVal = val[0]*retVal;
                    }else if (op[eq[1]]==4){
                        retVal = val[0]/retVal;
                    }
                }else{
                    if (op[eq[5]]==3){
                        tempVal = val[2]*val[3];
                    }else if (op[eq[5]]==4){
                        tempVal = val[2]/val[3];
                    }
                    if (op[eq[1]]==1){
                        retVal = val[0]+val[1];
                    }else if (op[eq[1]]==2){
                        retVal = val[0]-val[1];
                    }else if (op[eq[1]]==3){
                        retVal = val[0]*val[1];
                    }else if (op[eq[1]]==4){
                        retVal = val[0]/val[1];
                    }
                    if (op[eq[3]]==1){
                        retVal += tempVal;
                    }else if (op[eq[3]]==2){
                        retVal -= tempVal;
                    }else if (op[eq[3]]==3){
                        retVal *= tempVal;
                    }else if (op[eq[3]]==4){
                        retVal /= tempVal;
                    }
                }  
            }else{
                if (op[eq[1]]==1){
                    retVal = val[0]+val[1];
                }else if (op[eq[1]]==2){
                    retVal = val[0]-val[1];
                }
                if (op[eq[3]]==1){
                    retVal += val[2];
                }else if (op[eq[3]]==2){
                    retVal -= val[2];
                }
                if (op[eq[5]]==1){
                    retVal += val[3];
                }else if (op[eq[5]]==2){
                    retVal -= val[3];
                }
            }
            break;
    }
    return retVal;
}

void result24(vector<vector<string>> opPrm, vector<vector<float>> floatPrm, vector<vector<string>>* result){
    vector<string> form1, form2, form3, form4, form5, form6;
    float result1, result2, result3, result4, result5, result6;
    
    for (vector<float> floatSet : floatPrm){                    //dari setiap permutasi operand dan operator, dibuat
        for (vector<string> opSet : opPrm){                     //dalam bentuk persamaan yang sudah ditentukan

            form1.push_back(to_string(int(floatSet[0])));
            form1.push_back(opSet[0]);
            form1.push_back(to_string(int(floatSet[1])));
            form1.push_back(opSet[1]);
            form1.push_back(to_string(int(floatSet[2])));
            form1.push_back(opSet[2]);
            form1.push_back(to_string(int(floatSet[3])));

            form2.push_back("((");
            form2.push_back(to_string(int(floatSet[0])));
            form2.push_back(opSet[0]);
            form2.push_back(to_string(int(floatSet[1])));
            form2.push_back(")");
            form2.push_back(opSet[1]);
            form2.push_back(to_string(int(floatSet[2])));
            form2.push_back(")");
            form2.push_back(opSet[2]);
            form2.push_back(to_string(int(floatSet[3])));
            
            form3.push_back("(");
            form3.push_back(to_string(int(floatSet[0])));
            form3.push_back(opSet[0]);
            form3.push_back("(");
            form3.push_back(to_string(int(floatSet[1])));
            form3.push_back(opSet[1]);
            form3.push_back(to_string(int(floatSet[2])));
            form3.push_back("))");
            form3.push_back(opSet[2]);
            form3.push_back(to_string(int(floatSet[3])));
            
            form4.push_back(to_string(int(floatSet[0])));
            form4.push_back(opSet[0]);
            form4.push_back("((");
            form4.push_back(to_string(int(floatSet[1])));
            form4.push_back(opSet[1]);
            form4.push_back(to_string(int(floatSet[2])));
            form4.push_back(")");
            form4.push_back(opSet[2]);
            form4.push_back(to_string(int(floatSet[3])));
            form4.push_back(")");
            
            form5.push_back(to_string(int(floatSet[0])));
            form5.push_back(opSet[0]);
            form5.push_back("(");
            form5.push_back(to_string(int(floatSet[1])));
            form5.push_back(opSet[1]);
            form5.push_back("(");
            form5.push_back(to_string(int(floatSet[2])));
            form5.push_back(opSet[2]);
            form5.push_back(to_string(int(floatSet[3])));
            form5.push_back("))");
            
            form6.push_back("(");
            form6.push_back(to_string(int(floatSet[0])));
            form6.push_back(opSet[0]);
            form6.push_back(to_string(int(floatSet[1])));
            form6.push_back(")");
            form6.push_back(opSet[1]);
            form6.push_back("(");
            form6.push_back(to_string(int(floatSet[2])));
            form6.push_back(opSet[2]);
            form6.push_back(to_string(int(floatSet[3])));
            form6.push_back(")");

            result1 = evaluator(form1, floatSet, 1);    //menghitung hasil persamaan setiap bentuk
            result2 = evaluator(form2, floatSet, 2);
            result3 = evaluator(form3, floatSet, 3);
            result4 = evaluator(form4, floatSet, 4);
            result5 = evaluator(form5, floatSet, 5);
            result6 = evaluator(form6, floatSet, 6);
        
            if (floatEq(result1, 24.0)){                //pemmbandingan nilai float hasil perhitungan persamaan dengan
                result->push_back(form1);               //nilai 24.0, jika sama dimasukan ke vektor result
            }
            if (floatEq(result2, 24.0)){            
                result->push_back(form2);
            }
            if (floatEq(result3, 24.0)){
                result->push_back(form3);
            }
            if (floatEq(result4, 24.0)){
                result->push_back(form4);
            }
            if (floatEq(result5, 24.0)){
                result->push_back(form5);
            }
            if (floatEq(result6, 24.0)){
                result->push_back(form6);
            }
            form1.clear();
            form2.clear();
            form3.clear();
            form4.clear();
            form5.clear();
            form6.clear();     
        }
    }
}

#endif