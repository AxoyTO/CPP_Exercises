/*#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
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
}

void mstring::add(const char *c) {
    int l1 = strlen(str);
    int l2 = strlen(c);
    char *tmp = new char[l1 + l2 + 1];
    strcpy(tmp, str);
    strcpy(tmp + l1, c);
    str = new char[strlen(tmp) + 1];
    strcpy(str, tmp);
}

void mstring::insert(char c, int i) {
    int len = strlen(str);
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
}

void mstring::insert(const char *c, int i) {
    int l1 = strlen(str);
    int l2 = strlen(c);
    int lsum = l1 + l2;
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
}

void mstring::del(int i) {
    /* int j = 0, k = 0;
     int len = strlen(str);
     char *tmp = new char[len];
     for (j = 0; j < i; j++) {
         *(tmp + j) = *(str + j);
     }
     for (k = i + 1; k < len; k++) {
         *(tmp + j) = *(str + k);
     }

     strcpy(str, tmp);
     */
    int len = strlen(str);
    char *tmp = new char[len];
    strcpy(tmp, str);
    for (int j = i; j < len; j++) {
        *(tmp + j) = *(str + j + 1);
    }

    strcpy(str, tmp);

}

void mstring::del(int i, int j) {
    /*int k, len = strlen(str);
    char *tmp = new char[len];
    for (k = 0; k < i; k++) {
        *(tmp + k) = *(str + k);
    }
    for (int t = 0; t < (j - i); t++) {
        *(tmp + k) = *(str + j);
    }*/
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
}

void mstring::print() {
    cout << str << endl;
}

/*
int main() {
  /*  mstring s;
    //if(s.empty())
    //  cout << "empty"<< endl;
    s.add('a');
    s.print();
    //if(s.empty())
    //  cout << "empty2"<< endl;
    //if(!s.empty())
    //  cout << "not empty"<< endl;
    s.add("ben ve sen");
    s.print();
    s.insert('b', 0);
    s.print();
    cout << s.length() << endl;
    s.insert(" onlar", 12);
    s.print();
    s.del(0);
    s.print();
    s.del(0, 2);
    s.print();

    if(!s.empty())
        cout << "not empty2"<< endl;
    if(s.empty())
        cout << "empty3"<< endl;
    s.print();

    return 0;*/
    /*
    mstring s("hello world");
    //s.print();
    mstring s1 = s;
    //s1.print();
    mstring s2;
    //s2.print();
    cout << s.length() << endl;

    if (s2.empty()) {
        //cout << "S2 IS EMPTY!" << endl;
        s.add('!');
        s2.add("HI!");
        s.print();
        s2.print();
    }
    if (!s1.empty()) {
        //cout<<"S1 IS NOT EMPTY!" << endl;
        s1.insert(' ', 5);
        //s1.print();
        s1.insert('m', 6);
        s1.insert('y', 7);
        s.insert(" my", 5);
        s.print();
        s1.print();
    }
    s.del(9);
    s1.del(5, 7);
    s.print();
    s1.print();
    return 0;
}*/