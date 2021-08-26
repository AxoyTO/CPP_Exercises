#include <iostream>
#include <cmath>

using namespace std;

class Complex {
protected:
    double im;
    double re;
public:
    Complex(double a = 0, double b = 0) {
        re = a;
        im = b;
    }

    /*Complex(double a, double b) {  // Construct with 2 parameters
        re = a;
        im = b;
    }
    Complex(double a) {     // Конструктор преобразования
        re = a;
        im = 0;
    }
    Complex() {             // Constructor by default
        re = 0;
        im = 0;
    }
*/
    double modulo() { return sqrt(re * re + im * im); }

    double argument() { return atan2(im, re); }

    double get_re() { return re; }

    double get_im() { return im; }

    void print() { cout << re << "+" << im << "i" << endl; }

    ~Complex() {    //Деструктор, когда надо удалить объект
        cout << "Delete complex number" << endl;
    }
};

//"explicit" keyword --- bans implicit conversions

double pow2(Complex a) {
    return a.get_re() * a.get_re() + a.get_im() * a.get_im();
}

int main() {
    Complex z(3, 4);
    Complex z2(2);
    Complex z3;
    //Complex z4(7);
    z.print();
    z2.print();
    z3.print();
    cout << pow2(7.) << endl;
    cout << "|z| = " << z.modulo() << endl;
    cout << "Arg z = " << z.argument() << endl;
    return 0;
}