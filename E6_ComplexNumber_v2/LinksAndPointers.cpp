#include <iostream>

using namespace std;

int main() {
    int var_a = 23;
    int var_b = 45;

    const int* pt = &var_a; //  указатель на константу
    var_a++;    //var_a = 24
    //*pt = 3;  //error
    pt = &var_b;   //ok
    cout << *pt << endl;
    int* const ct = &var_a; //  константный указатель
    //ct = &var_b;  //error
    *ct = 57;
    cout << var_a << endl;
    const int * const st = &var_b;

    int i = 8;
    const int& ref_i = i ;
    i++;    // i = 9;
    //ref_i++;    //error;

    const int ci = 7;
    //int *ot = &ci;  //error
    //int *ptr = &ci;
    const int *ptr = &ci;

    const float var = 3.14;
    //float& ref_f = var; //error
    const float& ref_f = var;

    return 0;
}

