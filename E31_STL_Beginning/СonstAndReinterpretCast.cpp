/********************************************
 *****  Преобразование типов в С++  *****
 *******************************************/

#include <iostream>

class A {
};

class B : public A {
};

class C : public A {
};

using namespace std;

int main() {
    int i;
    double x = 3.14;
    i = x;      //неявное преобразование типов                  --- не рекомендуется!!!
    i = (int) x; //(casting) явное преобразование типов в стиле языка С    --- не рекомендуется!!!
    cout << "i = " << i << " x = " << x << endl;

    //const_cast
    const char *str = "abnjsjl";
    char *new_str = const_cast<char *>(str);

    const int &ref_i = i;
    int *k = const_cast<int *>(&ref_i);
    /*cout << k << endl;
    cout << *k << endl;
    cout << &ref_i << endl;
    cout << ref_i;
    */
    // static_cast
    i = static_cast<int>(x);
    C *pc;
    B *pb;
    pb = reinterpret_cast<B *>(pc);
    return 0;
}