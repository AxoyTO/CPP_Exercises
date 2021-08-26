#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

char *left(char *str, int N) {


    if (N < 0) {
        delete str;
        return str;
    }
    //cout << strlen(str);
    //str[1] = 'a';
    if (strlen(str) < N) {
        //cout << "strlen < N" << endl;
        return str;
    }
    char *newStr = (char *) malloc(100 * sizeof(char));
    for (int i = 0; i < N; i++) {
        *(newStr + i) = *(str + i);
    }
    str = newStr;
    //cout << str << endl;
    return str;
}

unsigned long left(unsigned long num, int N) {

    int i = 0;
    unsigned long t = 1, k = 1, tmpNum = num;
    while (tmpNum > 0) {
        tmpNum /= 10;
        i++;
    }
    //cout << "i=" << i << endl;
    //cout << tmpNum << endl;
    if (i < N) {
        return num;
    }
    if (N <= 0) {
        return 0;
    }
    tmpNum = num;

    for (int j = 0; j < N; j++) {
        t *= 10;
    }
    for (int j = 0; j < i; j++) {
        k *= 10;
    }

    //cout << "t=" << t << endl;
    //cout << "k=" << k << endl;
    k = k / t;
    //cout << "k=" << k << endl;
    num = num / k;

    return num;
}

int main() {
    char *str = (char *) malloc(100 * sizeof(char));
    unsigned long num;
    string con;
    string stringStr = "string";
    string numberStr = "number";
    int n;
    cin >> con;
    //cout << str << endl;

    if (con == stringStr) {
        //cout << "It's a string." << endl;
        cin >> str;
        cin >> n;
        //cout << str << endl << n;
        cout << left(str, n) << endl;
        //cout << *str << endl;
    } else if (con == numberStr) {
        //cout << "It's a number." << endl;
        cin >> num;
        cin >> n;
        cout << left(num, n) << endl;
        //cout << num << endl;
    }
    return 0;
}