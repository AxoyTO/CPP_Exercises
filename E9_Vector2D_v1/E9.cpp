/*#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
*/
class Vector_2d {
private:
    double x, y;
public:

    Vector_2d(double arg_x = 0, double arg_y = 0) {
        x = arg_x;
        y = arg_y;
    }

    const Vector_2d operator+(const Vector_2d &op);

    void print(const char *str) const;

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    friend const Vector_2d operator*(double a, const Vector_2d &op);

    const Vector_2d operator*(double a) const;

    const Vector_2d &operator+=(const Vector_2d &op);

    const Vector_2d &operator=(const Vector_2d &op);

    const Vector_2d operator-(const Vector_2d &op) const {
        return Vector_2d(x - op.x, y - op.y);      //anonymous content
    }

    const Vector_2d &operator++();

    const Vector_2d operator++(int);

    friend istream &operator>>(istream &is, Vector_2d &op);

    friend ostream &operator<<(ostream &os, const Vector_2d &op);

};

istream &operator>>(istream &is, Vector_2d &op) {
    is >> op.x >> op.y;
    return is;
}

ostream &operator<<(ostream &os, const Vector_2d &op) {
    os << "(" << op.x << "," << op.y << ")";
    return os;
}

const Vector_2d &Vector_2d::operator++() {
    x = x + 1.;
    y = y + 1.;
    return *this;
}

const Vector_2d Vector_2d::operator++(int) {
    Vector_2d tmp(x, y);
    x = x + 1.;
    y = y + 1.;
    return tmp;
}

const Vector_2d operator*(double a, const Vector_2d &op) {
    return Vector_2d(a * op.x, a * op.y);
}

const Vector_2d Vector_2d::operator*(double a) const {
    return Vector_2d(x * a, y * a);
}


const Vector_2d Vector_2d::operator+(const Vector_2d &op) {
    Vector_2d tmp;
    tmp.x = x + op.x;
    tmp.y = y + op.y;
    return tmp;
}


const Vector_2d &Vector_2d::operator+=(const Vector_2d &op) {
    x = x + op.x;
    y = y + op.y;
    return *this;
}

const Vector_2d &Vector_2d::operator=(const Vector_2d &op) {
    x = op.x;
    y = op.y;
    return *this;
}

void Vector_2d::print(const char *str = 0) const {
    if (str)
        cout << str << " = ";
    cout << "(" << x << "," << y << ")" << endl;
}
/*
int main() {

    int x = 1, l, s;       // initialization
    s = l = x = 5;        // appointing

    Vector_2d u(8, -7), v = Vector_2d(2, 3), w(v), y, z, t;
    v.print("v");
    u.print("u");
    cout << w;
    cout << "w = " << w << endl;
    u = w++;
    cout << "u = " << w << endl;
    cout << "w = " << w << endl;
    u = ++w;
    cout << "u = " << w << endl;
    cout << "w = " << u << endl;
    w = u + v;                  //u.operator+(v)    operator=
    u = 4 * w;
    u.print("4*w");
    u = w * 4;
    u.print("w*4");
    u = u * 4;
    u.print("u*4");
    //z = u + v + w;              //u.operator+(temp) temp<-v.operator+(w)   temp-временный объект
    //t = u + v + w + z;
    //w = u = v;                  //w.operator(u) operator=

    w.print("u+v = w");
    z.print("u+v+w = z");
    t.print("u+v+w+z = t");
    //y = u - v;
    y.print("u-v");
    (u - v).print("u-v");
    return 0;
}*/