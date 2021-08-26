/*****************
 * Шаблон Класса *
 ****************/

#include <iostream>
#include <cmath>

using namespace std;
//#define NUM 10 //Это плохо потому что заменит NUM во всей программе а не только в классе
//const int NUM = 10;   //Это плохо потому что

template<class T>
class Vector_2d {
private:
    //Нужно задать константу внутри класса
    //static const int NUM = 10;    //Тоже будет работать
    enum {
        NUM = 0
    };
    T x, y;
public:
    Vector_2d(T arg_x = NUM, T arg_y = NUM) : x(arg_x), y(arg_y) {}
    void print() const;
    T max_norm() const { return abs(x) > abs(y) ? abs(x) : abs(y); }
    const Vector_2d<T> &operator=(const Vector_2d<T> &op);
    const Vector_2d<T> operator*(T a){ return Vector_2d<T>(a*x, a*y);}
    template<typename V>    //Всегда используем другу букву!!
    friend const Vector_2d<V> operator+(const Vector_2d<V> &op1, const Vector_2d<V> &op2);
};

template<typename V> //здесь можно использовать любую, даже предыдущую, то есть T
const Vector_2d<V> operator+(const Vector_2d<V> &op1, const Vector_2d<V> &op2){
    Vector_2d<V> tmp;
    tmp.x = op1.x + op2.x;
    tmp.y = op1.y + op2.y;
    return tmp;
    //return Vector_2d<V>(op1.x+op2.x, op1.y +op2.y);
}

template<typename T>
const Vector_2d<T> &Vector_2d<T>::operator=(const Vector_2d<T> &op) {
    x = op.x;
    y = op.y;
    return *this;
}

template<typename T>
void Vector_2d<T>::print() const {
    cout << "(" << x << "," << y << ")" << endl;
}

/*
int main() {
    Vector_2d<int> v(2, 3), u(5,1), w;             //Указание типа объязательно
    v.print();
    u.print();
    w=u+v;
    w.print();
    Vector_2d<double> wd(3.14, 2.7), ud(1.1, 2.2), vd;
    wd.print();
    ud.print();
    vd = wd+ud;
    vd.print();
    cout << v.max_norm() << " " << u.max_norm() << " " << wd.max_norm() << endl;
    return 0;
}*/
