#include <iostream>
using namespace std;

int main() {
    int a = 7;
    int b = 12;
    int *ptr = &a;  //указатель
    int & ref_a = a; //ссылка
    a++;        //  a=8;
    (*ptr)++;   //  a=9;
    ref_a++;    //  a=10;
    ptr = &b;
    ref_a = b;  // a = 12;

    cout << "a = " << a << endl << "*ptr = " << *ptr << endl << "ref_a = " << ref_a;
    // &a == &ref_a -------> ALWAYS TRUE
    return 0;
}
