#include <iostream>

using namespace std;

static int a = 7;

void func() {
    static int count = 0;
}

class A {
private:
    int b;
    static int the_static;
public:
    A(int arg_b = 0) {
        b = arg_b;
        the_static++;
    }

    static void print_stat() {
        cout << "the static = " << the_static << endl;
        //cout << "b = " << b << endl;
    }

    void print() const {
        cout << "b = " << b << endl;
        cout << "the static = " << the_static << endl;
    }

    ~A() {
        the_static--;
    }
};

int A::the_static = 0;

int main() {
/*    cout << "A::the_static = " << A::the_static << endl;
    A a;
       a.b = 5;
     cout << "a.b = " << a.b << endl;
    cout << "A::the_static = " << A::the_static << endl;
    a.the_static = 8;
    cout << "A::the_static = " << A::the_static << endl;
    A::the_static = 10;
    cout << "A::the_static = " << a.the_static << endl;
    */

    A::print_stat();
    A a(5);
    a.print();
    A::print_stat();
    A c(7);

    a.print_stat();
    return 0;
}
