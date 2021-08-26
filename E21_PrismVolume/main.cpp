#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double a, b, c;
public:
    Triangle(double arg_a, double arg_b, double arg_c) {
        a = arg_a;
        b = arg_b;
        c = arg_c;
    }

    double area() {
        double p = (a + b + c) * 0.5;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Prisma {
    Triangle tr;    //Включение
    double H;
public:
    Prisma(double a, double b, double c, double arg_h) : tr(a, b, c), H(arg_h) {}

    double volume() { return tr.area() * H; }
};

/*
int main() {
    Triangle tr(3, 4, 5);
    Prisma pr(3, 4, 5, 7);
    cout << "S(tr) = " << tr.area() << endl;
    cout << "V(pr) = " << pr.volume() << endl;
    //tr = pr;
    return 0;
}*/