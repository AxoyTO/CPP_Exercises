#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cerrno>

using namespace std;

class Vec {
private:
    double *v;
    int len;
public:
    Vec(const int len, const double *vectorArray);

    Vec(const int len);

    Vec(const Vec &vector); //Copy
    void set(double arg, int coord);

    double get(const int coord);

    double euc_norma();

    double max_norma();

    void print();

    ~Vec() {
        delete[] v;
    }
};

Vec::Vec(const int len, const double *vectorArray) {

    if (len < 0)
        throw 'a';

    this->len = len;
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = vectorArray[i];
    }
}

Vec::Vec(const int len) {
    this->len = len;
    if (len < 0)
        throw 'a';
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = 0;
    }
}

Vec::Vec(const Vec &vector) {
    //if (len < 0)
    //    throw 1;

    len = vector.len;
    v = new double[len];
    for (int i = 0; i < len; i++) {
        v[i] = vector.v[i];
    }
}

void Vec::set(const double arg, const int coord) {
    if (coord < 0 || coord >= len) {
        throw 'c';
    }
    v[coord] = arg;
}

double Vec::get(const int coord) {
    if (coord < 0 || coord >= len) {
        throw 'b';
    }
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

double Vec::euc_norma() {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += v[i] * v[i];
    }

    /*if (sqrt(sum) < 0) {
        throw 'z';
    }*/
    return sqrt(sum);
}

double Vec::max_norma() {
    double max = 0;
    for (int i = 0; i < len; i++) {
        if (abs(v[i]) > max)
            max = abs(v[i]);
    }
    /*  if (max < 0) {
          throw 'z';
      }*/
    return max;
}

int main() {
    try {
        error();
    } catch (char c) {
        if (c == 'a')
            cerr << "Exception: length error" << endl;
        else if (c == 'b')
            cerr << "Exception: coordinate error in get()" << endl;
        else if (c == 'c')
            cerr << "Exception: coordinate error in set()" << endl;
    }
    catch (...) {
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}