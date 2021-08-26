#include <iostream>

class Vector {
private:
    double *v;
    int len;
public:
    Vector(double n) {
        len = n;
        v = (double *) malloc(sizeof(double) * n);
        for (int i = 0; i < n; i++) {
            v[i] = 0.;
        }
    }

    Vector(Vector &op) {
        len = op.len;
        v = (double *) malloc(sizeof(double) * len);
        for (int i = 0; i < len; i++) {
            v[i] = op.v[i];
        }
    }

    ~Vector() {
        free(v);
    }
}

};

int main() {
    return 0;
}
