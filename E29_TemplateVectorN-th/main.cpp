#include <iostream>

using namespace std;

class Exception {
private:
    string comment;
public:
    Exception(string arg_com) : comment(arg_com) {}

    Exception(const Exception &other) : comment(other.comment) {}

    string GetComment() const { return comment; }

    ~Exception() {}
};

class IndexException : public Exception {
private:
    int index;
public:
    IndexException(int arg_index, string arg_com) : index(arg_index), Exception(arg_com) {}

    IndexException(const IndexException &other) : index(other.index), Exception(other) {}

    int GetIndex() const { return index; }

    ~IndexException() {}
};

class LengthException : public Exception {
private:
    int len1, len2;
public:
    LengthException(int arg_len1, int arg_len2, string arg_com) : len1(arg_len1), len2(arg_len2), Exception(arg_com) {}

    LengthException(const LengthException &other) : len1(other.len1), len2(other.len2), Exception(other) {}

    int GetLen1() const { return len1; }

    int GetLen2() const { return len2; }

    ~LengthException() {}
};


template<class T>
class Vec {
private:
    T *v;
    int len;
public:
    Vec(int arg_len, const T *arg_arr);

    Vec(int arg_len);

    Vec(const Vec &other);

    void set(T arg, int coord);

    T get(int coord) const;

    T max_norm() const;

    //операция + сложения двух векторов
    template<typename V>
    friend const Vec<V> operator+(const Vec<V> &op1, const Vec<V> &op2);

    //операция * умножение вектора на действительное число
    template<typename V>
    friend const Vec<V> operator*(V n, const Vec<V> &op);

    template<typename V>
    friend const Vec<V> operator*(const Vec<V> &op, V n);

    //операцию ^ скалярного умножения двух векторов
    template<typename V>
    friend const V operator^(const Vec<V> &op1, const Vec<V> &op2);

    //операция = присваивание значений одного вектора другому вектору
    const Vec<T> &operator=(const Vec<T> &other);

    //операцию += прибавления значений одного вектора другому вектору
    const Vec<T> &operator+=(const Vec<T> &op1);

    //операция == проверки векторов на равенство
    const bool operator==(const Vec<T> &op);

    //операция [] индексации элементов вектора
    T &operator[](int i) const;

    //операция << вставка в выходной поток
    template<typename V>
    friend ostream &operator<<(ostream &os, const Vec<V> &op);

    ~Vec() {
        delete[]v;
    }
};

template<typename V>
ostream &operator<<(ostream &os, const Vec<V> &op) {
    os << "(";
    for (int i = 0; i < op.len; i++) {
        if (i == op.len - 1)
            os << op.v[i];
        else
            os << op.v[i] << ",";
    }
    os << ")";
    return os;
}

template<typename V>
const Vec<V> &Vec<V>::operator=(const Vec<V> &other) {
    if (len == other.len) {
        for (int i = 0; i < other.len; i++) {
            v[i] = other.v[i];
        }
    } else {
        delete[] v;
        len = other.len;
        v = new V[other.len];
        for (int i = 0; i < len; i++) {
            v[i] = other.v[i];
        }
    }
    return *this;
}

template<typename V>
const Vec<V> operator+(const Vec<V> &op1, const Vec<V> &op2) {
    if (op1.len != op2.len)
        throw LengthException(op1.len, op2.len, "Exception: addition of vectors of different lengths:");
    int len = op1.len;
    Vec<V> tmp(len);
    for (int i = 0; i < len; i++) {
        tmp.v[i] = op1.v[i] + op2.v[i];
    }
    return tmp;
}

template<typename T>
T Vec<T>::max_norm() const {
    T max = 0;
    for (int i = 0; i < len; i++) {
        if (abs(v[i]) > max)
            max = abs(v[i]);
    }
    return max;
}

template<typename T>
T Vec<T>::get(int coord) const {
    if (coord < 0 || coord >= len)
        throw Exception("Exception: coordinate error in get()");
    else
        return v[coord];
}

template<typename T>
void Vec<T>::set(T arg, int coord) {
    if (coord < 0 || coord >= len)
        throw Exception("Exception: coordinate error in set()");
    else
        v[coord] = arg;
}

template<typename V>
const Vec<V> operator*(V n, const Vec<V> &op) {
    int len = op.len;
    Vec<V> tmp(len);
    for (int i = 0; i < len; i++) {
        tmp.v[i] = op.v[i] * n;
    }
    return tmp;
}

template<typename V>
const Vec<V> operator*(const Vec<V> &op, V n) {
    int len = op.len;
    Vec<V> tmp(len);
    for (int i = 0; i < len; i++) {
        tmp.v[i] = op.v[i] * n;
    }
    return tmp;
}

template<typename V>
const bool Vec<V>::operator==(const Vec<V> &op) {
    int flag = 0;
    if (len == op.len) {
        for (int i = 0; i < len; i++) {
            if (v[i] != op.v[i])
                flag++;
        }
    } else if (len > op.len) {
        for (int i = 0; i < op.len; i++) {
            if (v[i] != op.v[i])
                flag++;
        }
        for (int i = op.len; i < len; i++) {
            if (v[i] != 0)
                flag++;
        }
    } else if (len < op.len) {
        for (int i = 0; i < len; i++) {
            if (v[i] != op.v[i])
                flag++;
        }
        for (int i = len; i < op.len; i++) {
            if (op.v[i] != 0)
                flag++;
        }
    }
    if (flag)
        return false;
    else
        return true;
}

template<typename V>
V &Vec<V>::operator[](int i) const {
    if (i >= len || i < 0)
        throw IndexException(i, "Exception: incorrect indexing:");
    return v[i];
}

template<typename V>
const V operator^(const Vec<V> &op1, const Vec<V> &op2) {
    if (op1.len != op2.len)
        throw LengthException(op1.len, op2.len, "Exception: multiplication of vectors of different lengths:");
    int len = op1.len;
    Vec<V> tmp(len);
    V sum = 0;
    for (int i = 0; i < len; i++) {
        tmp[i] = op1.v[i] * op2.v[i];
    }

    for (int i = 0; i < len; i++) {
        sum += tmp[i];
    }

    return sum;
}

template<typename V>
const Vec<V> &Vec<V>::operator+=(const Vec<V> &op1) {
    if (len != op1.len)
        throw LengthException(len, op1.len, "Exception: addition of vectors of different lengths:");
    for (int i = 0; i < len; i++)
        v[i] = v[i] + op1.v[i];
    return *this;
}

template<typename T>
Vec<T>::Vec(int arg_len, const T *arg_arr) {
    len = arg_len;
    if (len < 0)
        throw Exception("Exception: length error");

    v = new T[len];
    for (int i = 0; i < len; i++) {
        *(v + i) = *(arg_arr + i);
    }
}

template<typename T>
Vec<T>::Vec(int arg_len) {
    len = arg_len;
    if (len < 0)
        throw Exception("Exception: length error");
    v = new T[len];
    for (int i = 0; i < len; i++) {
        v[i] = 0;
    }
}

template<typename T>
Vec<T>::Vec(const Vec &other) {
    len = other.len;
    if (len < 0)
        throw Exception("Exception: length error");
    v = new T[len];
    for (int i = 0; i < len; i++) {
        *(v + i) = *(other.v + i);
    }
}

void Vector()
{
    double wd[3] = {1.5,2.3,-1.7};
    double wd2[4] = {1.1,2.3,4.5,6.7};
    Vec<double>  vd1(3, wd), vd2(4, wd2);
    vd2 += vd1;
    cout << "vd1 = " << vd1 << endl;
    cout << "vd2 = " << vd2 << endl;
    double prd = vd1^vd2;
    cout << "vd1^vd2 = " << prd << endl;
    vd2 = vd1 = vd1;
    cout << "vd2 = " << vd2 << endl;
}

int main() {
    try {
        Vector();
    }
    catch (LengthException &ex) {
        cerr << ex.GetComment() << " " << ex.GetLen1() << " " << ex.GetLen2() << endl;
    }
    catch (IndexException &ex) {
        cerr << ex.GetComment() << " " << ex.GetIndex() << endl;
    }
    catch (Exception &ex) {
        cerr << ex.GetComment() << endl;
    }
    catch (...) {
        cerr << "Exception: unknown error";
    }
    return 0;
}