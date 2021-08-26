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
    explicit Vec(int len);

    Vec(const double *v, int len);

    Vec(int len, const double *v);

    Vec(const Vec &op);

    const Vec operator+(const Vec &op) const;

    friend const Vec operator*(double n, const Vec &op);

    friend const Vec operator*(const Vec &op, double n);

    const Vec &operator=(const Vec &op);

    const bool operator==(const Vec &op);

    double &operator[](int i) const;

    friend ostream &operator<<(ostream &os, const Vec &op);

    void set(const double arg, const int coord);

    double get(const int coord) const;

    double euc_norm();

    double max_norm();

    void print() const;

    ~Vec() {
        delete[] v;
    }

};

ostream &operator<<(ostream &os, const Vec &op) {
    os << "(";
    for (int i = 0; i < op.len; i++) {
        if (op.len - 1 == i) {
            os << op.v[i];
        } else {
            os << op.v[i] << ",";
        }
    }
    os << ")";
    return os;
}

Vec::Vec(const int len, const double *v) {

    this->len = len;
    this->v = new double[len];
    for (int i = 0; i < len; i++)
        this->v[i] = v[i];
}

Vec::Vec(const double *v, const int len) {
    this->len = len;
    this->v = new double[len];
    for (int i = 0; i < len; i++) {
        this->v[i] = v[i];
    }

}

Vec::Vec(const int len) {
    this->len = len;
    v = new double[len];
    for (int i = 0; i < this->len; i++)
        this->v[i] = 0;

}

Vec::Vec(const Vec &op) {
    len = op.len;
    v = new double[len];
    for (int i = 0; i < len; i++)
        v[i] = op.v[i];
}

const Vec Vec::operator+(const Vec &op) const {
    Vec tmp(op.len);
    for (int i = 0; i < op.len; i++)
        tmp.v[i] = op.v[i] + v[i];
    return tmp;
}

const Vec operator*(double n, const Vec &op) {
    Vec tmp(op.len);
    for (int i = 0; i < op.len; i++) {
        tmp.v[i] = n * op.v[i];
    }
    return tmp;
}

const Vec operator*(const Vec &op, double n) {
    Vec tmp(op.len);
    for (int i = 0; i < op.len; i++) {
        tmp.v[i] = op.v[i] * n;
    }
    return tmp;
}


const Vec &Vec::operator=(const Vec &op) {

    if (this == &op)
        return *this;

    len = op.len;
    delete[] v;
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = op.v[i];
    }

    return *this;
}


void Vec::print() const {
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

void Vec::set(const double arg, const int coord) {
    if (coord >= 0 && coord < len)
        v[coord] = arg;
}

double Vec::get(const int coord) const {
    if ((coord < len) && coord >= 0)
        return v[coord];
    else return 0;
}

double &Vec::operator[](int i) const {
    return v[i];
}

const bool Vec::operator==(const Vec &op) {
    int flag = 0;
    //cout << "LEN = " << len << endl << "OP.LEN = " << op.len << endl;
    if (len == op.len) {
        //cout<< "db" << endl;
        for (int i = 0; i < len; i++) {
            if (v[i] != op.v[i])
                flag++;
        }
    } else if (len > op.len) {
        //cout << "db2" << endl;
        for (int i = 0; i < op.len; i++) {
            if (v[i] != op.v[i]) {
                //cout << "a";
                flag++;
            }
        }
        for (int i = op.len; i < len; i++) {
            if (v[i] != 0) {
                //cout << "b";
                flag++;
            }
        }
    } else if (len < op.len) {
        //cout << "db3" << endl;
        for (int i = 0; i < len; i++) {
            if (v[i] != op.v[i]) {
                //cout << "c";
                flag++;
            }
        }
        for (int i = len; i < op.len; i++) {
            if (op.v[i] != 0) {
                //cout << "d";
                flag++;
            }
        }
    }
    if (flag)
        return false;
    else
        return true;
}

/*
int main() {
    double y1[4] = {1, 2, 3, 4};
    double y2[4] = {-2, 1, 3, -3};
    //double y3[5] = {1, 2, 3, 4, 0};

    Vec u(4, y1), v(4, y2);
    Vec w(4);

    Vec a(4, y3);
    Vec b(4, y1);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    cout << "u = " << u <<
         endl;
    cout << "v = " << v <<
         endl;
    w = u = u;
    cout << "w = u = " << w <<
         endl;
    w = 4. * u + v * 3;
    cout << "w = 4.*u + v*3 = " << w <<
         endl;
    w[2] = 3;
    w[0] = -1;
    cout << "w = " << w <<
         endl;

    return 0;
}*/
