/*******************************************************
 *                Пространственные Фигуры              *
 ******************************************************/

#include <iostream>

using namespace std;

const double pi = 3.14159265358979323;

class figure {      //abstract class
private:
    int x, y, z;  //center
public:
    figure(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void move(int new_x, int new_y, int new_z) {
        x = new_x;
        y = new_y;
        z = new_z;
    }

    virtual void print() const {
        cout << "(" << x << "," << y << "," << z << ") ";
    }

    virtual double volume() = 0;

    virtual double area() = 0;

    virtual ~figure() {}
};

class cube : public figure {
private:
    int l;
public:
    cube(int arg_x, int arg_y, int arg_z, int arg_l) : figure(arg_x, arg_y, arg_z) {
        l = arg_l;
    }

    virtual void print() const {
        figure::print();
        cout << "l=" << l << endl;
    }

    virtual double area() { return 6 * l * l; }

    virtual double volume() { return l * l * l; }

    virtual ~cube() {}
};

class ball : public figure {
private:
    int r;
public:
    ball(int x, int y, int z, int r) : figure(x, y, z) {
        this->r = r;
    }

    virtual void print() const {
        figure::print();
        cout << "r=" << r << endl;
    }

    virtual double area() { return 4 * pi * r * r; }

    virtual double volume() { return (4. / 3) * pi * r * r * r; }

    virtual ~ball() {}
};

class cylinder : public figure {
private:
    int r, h;
public:
    cylinder(int x, int y, int z, int r, int h) : figure(x, y, z) {
        this->r = r;
        this->h = h;
    }

    virtual void print() const {
        figure::print();
        cout << "r=" << r << " h=" << h << endl;
    }

    virtual double area() { return 2 * pi * r * (r + h); }

    virtual double volume() { return pi * r * r * h; }

    virtual ~cylinder() {}
};


int main() {
    ball ba(1, 2, 3, 3);
    cube cu(2, 1, 3, 2);
    cylinder cy(3, 1, 2, 3, 4);
    ba.print();
    cout << "area ball = " << ba.area() << endl;
    cout << "volume ball = " << ba.volume() << endl;
    cu.print();
    cout << "area cube = " << cu.area() << endl;
    cout << "volume cube = " << cu.volume() << endl;
    cy.print();
    cout << "area cylinder = " << cy.area() << endl;
    cout << "volume cylinder = " << cy.volume() << endl;
    ba.move(0, 0, 0);
    ba.print();
    cu.move(-2, -5, -7);
    cu.print();
    cy.move(5, -9, 1);
    cy.print();

    return 0;
}