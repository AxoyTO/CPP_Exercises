#include <iostream>
#include <list>

using namespace std;

int main() {

    auto i = 42;    //int;
    auto l = 42L;   //long;
    auto db = 3.5;  //double;
    auto fl = 3.5f;

    cout << sizeof(i) << " " << sizeof(fl) << " " << sizeof(l) << " " << sizeof(db) << endl;
    list<int> li = {1, 2, 3, 4, 5};

    for (list<int>::iterator pl = li.begin(); pl != li.end(); pl++)
        cout << *pl << " ";
    cout << endl;

    for (auto pl = li.begin(); pl != li.end(); pl++)
        cout << *pl << " ";
    cout << endl;

    for (auto it:li)
        cout << it << " ";
    cout << endl;

    int arr[] = {10, 9, 8, 7, 6};
    for (auto &e: arr) {
        e *= e;
        cout << e << " ";
    }
    cout << endl;

    for (auto d: arr) {
        d *= d;
        cout << d << " ";
    }
    cout << endl;

    for (auto f: arr) {
        cout << f << " ";
    }
    cout << endl;
    return 0;
}