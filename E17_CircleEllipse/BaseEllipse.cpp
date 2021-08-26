/*#include <iostream>

using namespace std;

const double pi = 3.14159265358979323;
*/
class BaseEllipse {     //Class is abstract if there is at least one virtual function in it.
private:
    double x, y;
public:
    BaseEllipse(double arg_x, double arg_y) {
        x = arg_x;
        y = arg_y;
    }

    void Move(double sd_x, double sd_y) {
        x += sd_x;
        y += sd_y;
    }

    virtual void Print() const {
        cout << "(" << x << "," << y << ")";
    }

    virtual double area() = 0;  //чистая виртуальная функция
    virtual ~BaseEllipse() {}
};

class Circle : public BaseEllipse {
private:
    double r;
public:
    Circle(double arg_x, double arg_y, double arg_r) : BaseEllipse(arg_x, arg_y) {
        r = arg_r;
    }

    virtual void Print() const {
        BaseEllipse::Print();
        cout << " r = " << r << endl;
    }

    virtual double area() { return pi * r * r; }

    virtual ~Circle() {}
};

class Ellipse : public BaseEllipse {
private:
    double a, b, angle;
public:
    Ellipse(double arg_x, double arg_y, double arg_a, double arg_b, double al) : BaseEllipse(arg_x, arg_y) {
        a = arg_a;
        b = arg_b;
        angle = al;
    }

    virtual void Print() const {
        BaseEllipse::Print();
        cout << " a = " << a << " b = " << b << " angle = " << angle << endl;
    }

    virtual double area() {
        return pi * a * b;
    }

    virtual ~Ellipse() {}
};
/*
int main() {
    //BaseEllipse bel(2, 3);   //Error because this is an abstract class.
    Circle cl(1, 2, 3);
    Ellipse el(2, -1, 3, 4,pi/3);

    cout << "area cl = " << cl.area() << endl;
    cout << "area el = " << el.area() << endl;

    cl.Print();
    el.Print();

    BaseEllipse *Bl[3];
    Bl[0] = new Circle(2, 3, 5);
    Bl[1] = new Ellipse(-1, 2, 3, 4,pi/6);
    Bl[2] = new Ellipse(0, 5, 2, 5, pi/4);
    for (int i = 0; i < 3; i++) {
        Bl[i]->Print();
    }
    for (int i = 0; i < 3; i++) {
        Bl[i]->Move(1, 2);
    }
    for (int i = 0; i < 3; i++) {
        Bl[i]->Print();
    }
    for (int i = 0; i < 3; i++) {
        delete Bl[i];
    }
    return 0;
}*/