class Quotient {
    int chis, znam;
public:
    Quotient(int a = 0, int b = 1) {
        chis = a;
        znam = b;
    }

    void print() {
        if (chis == 0 || (chis != 0 && znam == 1))
            cout << chis << endl;
        else {
            int i = chis, j = znam, k = chis % znam;
            while (k != 0) {
                i = j;
                j = k;
                k = (i % j);
            }
            if (j != 0) {
                chis = chis / j;
                znam = znam / j;
            }
            cout << chis << "/" << znam << endl;
        }
    }
};
