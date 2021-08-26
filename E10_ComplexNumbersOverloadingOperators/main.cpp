/*#include <iostream>

using namespace std;
*/
class Complex {
private:
    double re;
    double im;
public:
    Complex();

    Complex(double re, double im = 0);

    friend ostream &operator<<(ostream &os, const Complex &op);

    const Complex operator+(const Complex &op) const;

    friend const Complex operator+(double n, const Complex &op);

    const Complex operator-(const Complex &op) const;

    friend const Complex operator-(double n, const Complex &op);

    const Complex operator*(const Complex &op) const;

    friend const Complex operator*(double n, const Complex &op);

    friend const Complex operator*(const Complex &op, double n);

    const Complex &operator=(const Complex &op);

    const bool operator==(const Complex &op);
};

ostream &operator<<(ostream &os, const Complex &op) {
    if (op.re == 0) {
        if (op.im == 0)
            os << op.re;
        else if (op.im == 1)
            os << "i";
        else if (op.im == -1)
            os << "-i";
        else
            os << op.im << "i";
    } else {
        if (op.im == 0)
            os << op.re;
        else if (op.im == 1)
            os << op.re << "+i";
        else if (op.im == -1)
            os << op.re << "-i";
        else {
            if (op.im > 0)
                os << op.re << "+" << op.im << "i";
            else
                os << op.re << op.im << "i";
        }
    }
    return os;
}

Complex::Complex() {
    re = 0.;
    im = 0.;
}

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

const Complex Complex::operator+(const Complex &op) const {
    Complex tmp;
    tmp.re = re + op.re;
    tmp.im = im + op.im;
    return tmp;
}

const Complex operator+(double n, const Complex &op) {
    return Complex(op.re + n, op.im);
}

const Complex Complex::operator-(const Complex &op) const {
    Complex tmp;
    tmp.re = re - op.re;
    tmp.im = im - op.im;
    return tmp;
}

const Complex operator-(double n, const Complex &op) {
    return Complex(n-op.re, op.im);
}

const Complex Complex::operator*(const Complex &op) const {
    return Complex(re * op.re - im * op.im,
                   re * op.im + im * op.re);
}

const Complex operator*(double n, const Complex &op) {
    return Complex(op.re * n, op.im * n);
}

const Complex operator*(const Complex &op, double n) {
    return Complex(op.re * n, op.im * n);
}

const Complex &Complex::operator=(const Complex &op) {
    re = op.re;
    im = op.im;
    return *this;
}

const bool Complex::operator==(const Complex &op){
    if (op.re == re && op.im == im)
        return true;
    else
        return false;
}
/*
int main() {
    Complex c(1, -2), g(3), v;
    cout << "c = " << c << endl;
    cout << "g = " << g << endl;
    cout << "v = " << v << endl;
    v = 4. * c * 2.;
    cout << "v = " << v << endl;
    g = 3. - g + c - 2. * v;
    cout << "g = " << g << endl;
    cout << "2.*g*v = " << 2. * g * v << endl;
    v = g = c;
    if (c == g)
        v = 2. * Complex(0, 1);
    else
        v = 2.;
    cout << "c = " << c << " g = " << g << "v = " << v << endl;
    return 0;
}
*/