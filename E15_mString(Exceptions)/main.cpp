#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class ExceptionHandler {
private:
    string comment, funcName, codeStr;
    int err_code, n1, n2;
public:
    //insert1and2parameters(1) --- delete1parameter(2) ---- delete2parameters(3)  ---- length(4)
    ExceptionHandler(int p1, int p2, int func) {
        err_code = func;
        n1 = p1;
        n2 = p2;
        if (func == 1) {
            funcName = "insert";
            codeStr = to_string(n1);
            comment = "Exception: problem in " + funcName + " incorrect parameter: " + codeStr;
        } else if (func == 2) {
            funcName = "delete";
            codeStr = to_string(n1);
            comment = "Exception: problem in " + funcName + " incorrect parameter: " + codeStr;
        } else if (func == 3) {
            funcName = "delete";
            codeStr = to_string(n1) + " " + to_string(n2);
            comment = "Exception: problem in " + funcName + " incorrect parameter: " + codeStr;
        } /*else if (func == 4) {
            funcName = "length";
            codeStr = to_string(n1);
            comment = "Exception: problem in " + funcName + " incorrect parameter: " + codeStr;
        }*/
    }

    const string

    getComment() const {
        return comment;
    }

    const string getFuncName() const {
        return funcName;
    }

    const int getErrCode() const {
        return err_code;
    }

};

/*
class ExceptionHandlerInsert {
private:
    string comment, funcName;
    int p1;
public:
    ExceptionHandlerInsert(int p1, string funcName) {
        this->p1 = p1;
        comment = "Exception: problem in " + funcName + " incorrect parameter: ";
    }
};

class ExceptionHandlerDelete_1 {
private:
    string comment, funcName;
    int p1;
public:
    ExceptionHandlerDelete_1(int p1) {
        this->p1 = p1;
        this->funcName = funcName;
        comment = "Exception: problem in " + funcName + " incorrect parameter: ";
    }

    string getParameter() const
    {
        return to_string(p1);
    }
};
*/
class mstring {
private:
    char *str;
public:
    mstring();     //по умольчанию
    mstring(const mstring &str);     //копирования
    mstring(const char *str);     //преобразования из строки в стиле C

    int length() {
        return strlen(str);
    }

    bool empty() {
        if (str[0] == str[strlen(str)])
            return true;
        else
            return false;
    }

    void add(char c);    //c - symbol
    void add(const char *c); //c - string
    void insert(char c, int i);  //c - symbol, i - coordinate
    void insert(const char *c, int i);   //c - string, i - coordinate
    void del(int i); //i - coordinate
    void del(int i, int j);  //i,j - coordinates(from i to j)
    void print();

    ~mstring() {
        delete[]str;
    }
};

mstring::mstring() {
    str = new char[0];
    str[0] = '\0';
    //cout << "default constructor called -> string is: " << str << endl;
}

mstring::mstring(const mstring &str) {
    this->str = new char[strlen(str.str) + 1];
    strcpy(this->str, str.str);
    //cout << "copy constructor called -> string is: " << this->str << endl;
}

mstring::mstring(const char *str) {
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
    //cout << "transformation constructor called -> string is: " << str << endl;
}

void mstring::add(char c) {
    int len = strlen(str);
    char *tmp = new char[len + 1];
    strcpy(tmp, str);
    *(tmp + len) = c;
    strcpy(str, tmp);
    delete[]tmp;
}

void mstring::add(const char *c) {
    int l1 = strlen(str);
    int l2 = strlen(c);
    char *tmp = new char[l1 + l2 + 1];
    strcpy(tmp, str);
    strcpy(tmp + l1, c);
    str = new char[strlen(tmp) + 1];
    strcpy(str, tmp);
    delete[]tmp;
}

void mstring::insert(char c, int i) {
    int len = strlen(str);
    if (i < 0 || i > len) {
        throw ExceptionHandler(i, 0, 1);
    }

    char *tmp = new char[len + 2];
    int j;
    for (j = 0; j < i; j++) {
        *(tmp + j) = *(str + j);
    }
    tmp[j] = c;
    for (j = i + 1; j < len + 2; j++) {
        *(tmp + j) = *(str + j - 1);
    }
    strcpy(str, tmp);
    delete[]tmp;
}

void mstring::insert(const char *c, int i) {
    int l1 = strlen(str);
    int l2 = strlen(c);
    int lsum = l1 + l2;

    if (i < 0 || i > strlen(str)) {
        throw ExceptionHandler(i, 0, 1);
    }

    char *tmp = new char[l1 + l2 + 1];
    int j;
    for (j = 0; j < i; j++) {
        *(tmp + j) = *(str + j);
    }
    l2 += j;
    int k = j;
    for (j = i; j < l2; j++) {
        *(tmp + j) = *(c++);
    }
    for (; j < lsum; j++) {
        *(tmp + j) = *(str + k++);
    }

    strcpy(str, tmp);
    delete[]tmp;
}

void mstring::del(int i) {

    if (i < 0 || i >= strlen(str)) {
        throw ExceptionHandler(i, 0, 2);
    }

    int len = strlen(str);
    char *tmp = new char[len];
    strcpy(tmp, str);
    for (int j = i; j < len; j++) {
        *(tmp + j) = *(str + j + 1);
    }

    strcpy(str, tmp);
    delete[]tmp;
}

void mstring::del(int i, int j) {

    if (i < 0 || i >= strlen(str) || j < 0 || j >= strlen(str) || i > j) {
        throw ExceptionHandler(i, j, 3);
    }

    int len = strlen(str);
    int dif = j - i;
    char *tmp = new char[len - dif + 1];
    int m, n;
    for (m = 0; m < i; m++) {
        *(tmp + m) = *(str + m);
    }
    for (n = j + 1; n < len; n++) {
        *(tmp + m) = *(str + n);
        m++;
    }
    strcpy(str, tmp);
    delete[]tmp;
}

void mstring::print() {
    cout << str << endl;
}

void error()
{
    mstring s ("hello world");
    mstring s1 = s;
    mstring s2;
    if (!s1.empty())
    {
        s1.insert(' ', 5);
        s1.insert('m',6);
        s1.insert('y',7);
        s.insert(" my",5);
        s.print();
        s1.print();
    }
    s.del(9);
    s1.del(-5,7);
    s.print();
    s1.print();
}

int main() {
    try {
        error();
    }
    catch (ExceptionHandler &ex) {
        cerr << ex.getComment() << endl;
    }
    return 0;
}