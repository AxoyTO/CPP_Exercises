#include <iostream>

using namespace std;

int &max(int *arr, int n) {
    int imax = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > arr[imax])
            imax = i;

    return arr[imax];
}

int main() {

    int A[5] = {1, 3, 8, 4, 5};
    max(A,5) = -3;  // arr[imax] = -3;
    for(int i = 0; i<5; i++)
        cout << A[i] << " ";

    return 0;
}

