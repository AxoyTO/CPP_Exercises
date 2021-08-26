#include <iostream>

using namespace std;

template<typename T>
T maxn(T *arr, int n) {
    T max = *arr;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) >= max)
            max = *(arr + i);
    }
    return max;
}

template<>
const char *maxn(const char *str[], int n) {
    int *count = new int[n];
    int tmp = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (*(str[i] + j) != 0) {
            (*(count + i))++;
            j++;
        }
    }

    /*for (int i = 0; i < n; i++)
        cout << *(count + i) << " ";
    cout << endl;
    */

    for (int i = 0; i < n; i++) {
        if (*(count + i) > tmp) {
            tmp = *(count + i);
            maxIndex = i;
        }
    }
    //cout << maxIndex << endl;
    //cout << *(str + maxIndex);

    delete[]count;
    return *(str + maxIndex);
}

/*
int main()
{
    using namespace std;
    int arri[6] = {1, 2, 5, 3, 1, -1};
    double arrd[4] = {2.3, -1.3, 8.7, 4.5};
    const char * arrc[5] = {"first", "second", "third", "long string", "another string"};

    cout << "max of integer = " << maxn(arri, 6) << endl;
    cout << "max of double = " << maxn(arrd, 4) << endl;
    cout << "max string is " << maxn(arrc, 5) << endl;

    return 0;
}*/