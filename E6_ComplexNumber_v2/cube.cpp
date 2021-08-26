#include <iostream>
using namespace std;

double cube(double a)
{
    a *= a*a;
    return a;
}

double refcube(double& a)
{
    a *= a*a;
    return a;
}

int main() {

    double x = 3.;
    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}
