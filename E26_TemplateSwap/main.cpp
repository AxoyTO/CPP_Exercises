#include <iostream>

using namespace std;

struct Pers {
    char name[20];
    int num_int;
    double num_double;
};

template<typename T>
void Swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
    //cout << "T " << endl;
}

template<>
//Явная специализация --- ВСЕГДА ПОСЛЕ ШАБЛОНА
void Swap<Pers>(Pers &j1, Pers &j2) {
    int tmp_i = j1.num_int;
    double tmp_d = j1.num_double;
    j1.num_int = j2.num_int;
    j1.num_double = j2.num_double;
    j2.num_int = tmp_i;
    j2.num_double = tmp_d;
}

template<typename T>
void Swap(T *a, T *b, int n) {
    for (int i = 0; i < n; i++) {
        T tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    //cout << "int" << endl;
}

/*void Swap(double &a, double &b) {
    int tmp = a;
    a = b;
    b = tmp;
    cout <<"double" << endl;
}*/

template<typename T>
void Print(T *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template<typename T, typename D>
void Print2(T &a, D &b) {
    cout << "type T " << a << " type D " << b << endl;
}

template<typename T>
//Частичная специализация
void Print2(T &a, int &b) {
    cout << "type T " << a << " int " << b << endl;
}

template<>
//явная или полная специализация
void Print2(int &a, int &b) {
    cout << " int " << a << " int " << b << endl;
}

//Компильятор выбирает функцию если она есть, если нет, создает сам новую функцию из шаблона.

int main() {
    int i = 12, j = 15;
    double x = 3.14, y = 2.7;

    Print2(i, x);  //общий шаблон <int,double>
    Print2(y, j);  //частичная специализация
    Print2(i, j);  //явная или полная специализация
    cout << "i = " << i << " j = " << j << endl;
    Swap(i, j);        //Компильятор сам понимает, что это int ---> <int> не объязательно
    cout << "i = " << i << " j = " << j << endl;

    cout << "x = " << x << " y = " << y << endl;
    Swap(x, y);     //Компильятор сам понимает, что это double ---> <double> не объязательно
    cout << "x = " << x << " y = " << y << endl;

    double *a, *b;
    a = new double[5];
    b = new double[5];
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
        b[i] = 10 - i;
    }
    Print(a, 5);
    Print(b, 5);
    Swap(a, b, 5);
    Print(a, 5);
    Print(b, 5);
    delete[]a;
    delete[]b;
    double aa[5] = {0, 1, 2, 3, 4};
    double bb[5] = {5, 6, 7, 8, 9};
    Print(aa, 5);
    Print(bb, 5);
    Swap(aa, bb, 5);
    Print(aa, 5);
    Print(bb, 5);
    Pers P1 = {"A", 23, 3.14};
    Pers P2 = {"B", 34, 2.7};
    cout << "P1: " << P1.name << " " << P1.num_int << " " << P1.num_double << endl;
    cout << "P2: " << P2.name << " " << P2.num_int << " " << P2.num_double << endl;
    Swap(P1, P2);
    cout << "P1: " << P1.name << " " << P1.num_int << " " << P1.num_double << endl;
    cout << "P2: " << P2.name << " " << P2.num_int << " " << P2.num_double << endl;
    return 0;
}