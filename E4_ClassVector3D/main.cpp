#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Vector_3d {
    double x, y, z;
public:
    Vector_3d(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }

    Vector_3d() {       //Constructor by default
        x = 0;
        y = 0;
        z = 0;
    }

    Vector_3d(double a) {
        x = a;
        y = 0;
        z = 0;
    }

    void print() {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }

    double euc_norm() {
        return sqrt(get_x() * get_x() + get_y() * get_y() + get_z() * get_z());
    }

    double max_norm() {
        if(abs(x)>=abs(y) && abs(x)>=abs(z))
            return abs(x);
        if(abs(y)>=abs(x) && abs(y)>=abs(z))
            return abs(y);
        if(abs(z)>=abs(x) && abs(z)>=abs(y))
            return abs(z);
    }

    double get_x() {
        return x;
    }

    double get_y() {
        return y;
    }

    double get_z() {
        return z;
    }

    void set(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }

    /*~Vector_3d() {
    }*/
};

//Компилятор сам добавит конструктор и деструктор если их нет
int main() {
    Vector_3d v(1.5, 2.4, 3.);
    Vector_3d w, u = 2.;
    v.print();
    w.print();
    u.print();
    cout << "norma euc v = " << v.euc_norm() << endl;
    w.set(1, 2, -3);
    cout << "norma max w = " << w.max_norm() << endl;
    // В вводе на сайте есть лишние пробелы
    // Их нет в выводе
    cout << "u_x = " << u.get_x() << endl;
    cout << "w_y = " << w.get_y() << endl;
    cout << "v_z = " << v.get_z() << endl;
    return 0;
}   //Вызов деструктора
