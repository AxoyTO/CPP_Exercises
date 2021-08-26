/***************************************************************
 *              Классы Окружность и Эллпис                    *
 **************************************************************/

#include <iostream>

using namespace std;

const double pi = 3.14159265358979323;

class Circle {
private:
    double x, y;
protected:
    double r;
public:
    Circle(double arg_x, double arg_y, double arg_r) {
        x = arg_x;
        y = arg_y;
        r = arg_r;
    }

    void Move(double sd_x, double sd_y) {
        x += sd_x;
        y += sd_y;
    }

    virtual double area() { return pi * r * r; }

    virtual void Print() const;

    virtual ~Circle() {}
};

void Circle::Print() const {
    cout << "(" << x << "," << y << ")";
    cout << " r = " << r << endl;
}

class Ellipse : public Circle {
private:
    double a;
public:
    Ellipse(double arg_x, double arg_y, double arg_r, double arg_a) : Circle(arg_x, arg_y, arg_r) {
        a = arg_a;
    }

    virtual double area() const { return pi * a * r; }

    virtual void Print() const;

    virtual ~Ellipse() {}
};

void Ellipse::Print() const {
    Circle::Print();
    //cout << "(" << x << "," << y << ")";
    cout << "a = " << a << endl;
}

int main() {
    Circle cl(1, 2, 3);
    Ellipse el(2, -1, 3, 4);
    Circle &rcl = el;
    cout << "area cl = " << cl.area() << endl;
    cout << "area el = " << el.area() << endl;
    cl.Print();
    el.Print();
    rcl.Print();

    return 0;
}
