/*#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
*/
class Vec {
private:
    double *v;
    int len;
public:
    Vec(const int len, double *vectorArray);

    Vec(const int len);

    Vec(const Vec &vector); //Copy
    void set(double arg, int coord);

    double get(const int coord);

    double euc_norm();

    double max_norm();

    void print();

    ~Vec() {
        delete[] v;
    }
};

Vec::Vec(const int len, double *vectorArray) {
    this->len = len;
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = vectorArray[i];
    }
}

Vec::Vec(const int len) {
    this->len = len;
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = 0;
    }
}

Vec::Vec(const Vec &vector) {
    len = vector.len;
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = vector.v[i];
    }
}

void Vec::set(const double arg, const int coord) {
    if (coord >= 0 && coord < len)
        v[coord] = arg;
}

double Vec::get(const int coord) {
    if ((coord < len) && coord >= 0)
        return v[coord];
    else return 0;
}

void Vec::print() {
    cout << "(";
    for (int i = 0; i < len; i++) {
        cout << v[i];
        if (i != (len - 1))
            cout << ",";
    }
    cout << ")" << endl;
}

double Vec::euc_norm() {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

double Vec::max_norm() {
    double max = 0;
    for (int i = 0; i < len; i++) {
        if (abs(v[i]) > max)
            max = abs(v[i]);
    }
    return max;
}
/*
int main(void) {
    double y1[3] = {1, 2, 3};
    double y2[5] = {2, 1, 0, 5, 7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;

    y.print();
    x.print();
    z.print();
    u.print();
    x.set(23, 2);
    x.set(-5, -3);
    u.set(34, 1);
    z.set(-3, 3);
    cout << "x[2] = " << x.get(2) << endl;
    //cout << "x[2] = " << x.get(-3) << endl;
    cout << "u[1] = " << u.get(1) << endl;
    cout << "euc_norma y: " << y.euc_norm() << endl;
    cout << "max_norma z: " << z.max_norm() << endl;
    return 0;
}*/