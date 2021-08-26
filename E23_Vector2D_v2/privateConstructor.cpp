#include <iostream>

using namespace std;

class A {
private:
    int b;

    A(int arg_b) { b = arg_b; }

public:
    static A create(int arg_b = 0) { return A(arg_b); }

    void print() const {
        cout << "b = " << b << endl;
    }
};

int main() {
    A a = A::create(4);
    a.print();
}