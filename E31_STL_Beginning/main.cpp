#include <iostream>

using namespace std;

template<class T, class D = long>
class Vector_2d {
private:
    T x;
    D y;
public:
    Vector_2d(T arg_x, D arg_y) : x(arg_x), y(arg_y) {
    }

    void print() const { cout << "(" << x << "," << y << ")" << endl; }

    T get_x() const { return x; }

    D get_y() const { return y; }

    Vector_2d<T, D> &operator=(const Vector_2d<T, D> &op) {
        x = op.x;
        y = op.y;
        return *this;
    }

    template<typename V, typename U>
    friend const Vector_2d<V, U> operator+(const Vector_2d<V, U> &op1, const Vector_2d<V, U> &op2);
};

template<typename V, typename U>
const Vector_2d<V, U> operator+(const Vector_2d<V, U> &op1, const Vector_2d<V, U> &op2) {
    Vector_2d<V, U> tmp(0, 0);
    tmp.x = op1.x + op2.x;
    tmp.y = op1.y + op2.y;
    return tmp;
}

template<class T>          //частичная специализация
class Vector_2d<T, int> {

};

template<>                 //явная/полная специализация
class Vector_2d<long, short> {

};

int main() {
    Vector_2d<int, double> vid(2, 3.14), uid(3, 2.7), wid(0, 0.);
    vid.print();
    uid.print();
    wid.print();
    Vector_2d<long, short> vls(7,8);            //явная/полная специализация
    Vector_2d<double, long> vdl(7.8, 17L);
    Vector_2d<double> vd(9.5, 8);   //Vector_2d<double,long>
    Vector_2d<float, int> vfi(3.7, 78);               //Частичная специализация
    return 0;
}
