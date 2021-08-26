#include<iostream>
#include <cmath>
#include <cstdlib>
#include <cerrno>

using namespace std;

class ExceptionHandler {
private:
    int len1, len2, index, err_code;
    string comment;
public:
    ExceptionHandler(int len1, int len2) {
        this->len1 = len1;
        this->len2 = len2;
        err_code = 1;
        comment = "Exception: addition of vectors of different lengths: ";
        string str1 = to_string(len1);
        string str2 = to_string(len2);
        comment = comment + str1 + " " + str2;
    }

    explicit ExceptionHandler(int index) {
        len1 = len2 = 0;
        this->index = index;
        err_code = 2;
        comment = "Exception: incorrect indexing: ";
        string str1 = to_string(index);
        comment += str1;
    }

    ExceptionHandler(){
        len1 = len2 = 0;
        err_code = 3;
        comment = "Exception: unknown error";
    }

    ExceptionHandler(const ExceptionHandler &op) {
        len1 = op.len1;
        len2 = op.len2;
        index = op.index;
    }

    string getComment() {
        return comment;
    }

    int getLen1() {
        return len1;
    }

    int getLen2() {
        return len2;
    }

    int getIndex() {
        return index;
    }

    int getErrorCode() {
        return err_code;
    }
};

class Vec : ExceptionHandler {
private:
    double *v;
    int len;
public:
    explicit Vec(int len);

    Vec() = default;

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

    double euc_norma();

    double max_norma();

    void print() const;

    ~Vec() {
        if(len!=0)
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
    if(len<=0)
        throw ExceptionHandler();
    this->len = len;
    this->v = new double[len];
    for (int i = 0; i < len; i++)
        this->v[i] = v[i];
}

Vec::Vec(const double *v, const int len) {
    if(len<=0)
        throw ExceptionHandler();
    this->len = len;
    this->v = new double[len];
    for (int i = 0; i < len; i++) {
        this->v[i] = v[i];
    }

}

Vec::Vec(const int len) {
    if(len<=0)
        throw ExceptionHandler();
    this->len = len;
    v = new double[len];
    for (int i = 0; i < this->len; i++)
        this->v[i] = 0;

}

Vec::Vec(const Vec &op) {
    if(len<=0)
        throw ExceptionHandler();
    len = op.len;
    v = new double[op.len];
    for (int i = 0; i < op.len; i++)
        v[i] = op.v[i];
}

const Vec Vec::operator+(const Vec &op) const {

    if (len != op.len) {
        throw ExceptionHandler(len, op.len);
    }
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
    if (this->len == op.len) {
        for (int i = 0; i < op.len; i++) {
            v[i] = op.v[i];
        }
    } else {
        delete[] v;
        len = op.len;
        v = new double[op.len];
        for (int i = 0; i < op.len; i++) {
            v[i] = op.v[i];
        }
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

double Vec::euc_norma() {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += v[i] * v[i];
    }

    if (sqrt(sum) < 0) {
        throw ExceptionHandler();
    }

    return sqrt(sum);
}

double Vec::max_norma() {
    double max = 0;
    for (int i = 0; i < len; i++) {
        if (abs(v[i]) > max)
            max = abs(v[i]);
    }

    if (max < 0) {
        throw ExceptionHandler();
    }

    return max;
}

void Vec::set(const double arg, const int coord) {
    if (coord < 0 || coord > len) {
        throw ExceptionHandler();
    }
    if (coord >= 0 && coord < len)
        v[coord] = arg;
}

double Vec::get(const int coord) const {
    if (coord < 0 || coord > len) {
        throw ExceptionHandler();
    }
    if ((coord < len) && coord >= 0)
        return v[coord];
    else return 0;
}

double &Vec::operator[](int i) const {
    if(i>len || i<0)
        throw ExceptionHandler(i);
    return v[i];
}

const bool Vec::operator==(const Vec &op) {
    int flag = 0;
    len = op.len;
    for (int i = 0; i < len; i++) {
        if (v[i] != op.v[i])
            flag++;
    }
    if (flag)
        return false;
    else
        return true;
}
/*void error()
{
    Vec v1(3), v2(5), v3();

    v3 = v1+v2;

}*/
int main() {
    try {
        error();
    }
    catch (ExceptionHandler &ex) {
            cerr << ex.getComment();
    }
    return 0;

}