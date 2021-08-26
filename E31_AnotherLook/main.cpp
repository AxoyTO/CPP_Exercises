/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cerrno>
using namespace std;
class Error{
    char sym;
    int i;
    int j;
public:
    Error(char sym,int i,int j){
        this->sym=sym;
        this->i=i;
        this->j=j; }
    const char get_sym(){return this->sym;}
    const int get_i(){return this->i;}
    const int get_j(){return this->j; }

};

template<typename T>
class Vec{
    T *v;
    int len;
public:
    Vec<T>(int len, T *array);
    Vec<T>(T *array,int len);
    Vec<T>(int len=0);
    Vec<T>(const Vec<T> &coord);
    void set(T arg,int coord);
    //   void print();
    T get(int coord);
    T euc_norm();
    T max_norm() const;
    T & operator[](int i);
    Vec<T>& operator += (const Vec<T>& op);
    template<typename V>
    friend const Vec<V> operator+(const Vec<V>& op1, const Vec<V>& op2);
    Vec<T> &operator=(const Vec<T>& op);
    template<typename V>
    friend const Vec<V> operator *(const Vec<V>& op, double a);
    template<typename V>
    friend const Vec<V> operator *(double a, const Vec<V>& op);
    template<typename V>
    friend const V operator ^(const Vec<V>& op1, const Vec<V>& op2);
    template<typename V>
    friend bool operator ==(const Vec<V>& op1, const Vec<V>& op2);
    template<typename V>
    friend ostream& operator<<(ostream& os, const Vec<V>& op);
    ~Vec<T>(){delete [] v;}
};

template<typename T>
T& Vec<T>::operator[](int i){
    if (i>this->len || i<0) { throw Error ('i', i, 0); }
    return v[i];}

template<typename V>
const Vec<V> operator*(const Vec<V>& op, double a)
{
    Vec<V> tmp(op.len);
    for (int i=0;i<op.len;i++)
    {tmp.v[i] = a*op.v[i];} return tmp;
}

template<typename V>
const Vec<V> operator*( double a, const Vec<V>& op)
{
    Vec<V> tmp(op.len);
    for (int i=0;i<op.len;i++)
    {tmp.v[i] = a*op.v[i];} return tmp;
}

template<typename V>
const Vec<V> operator+(const Vec<V>& op1, const Vec<V>& op2)
{   if (op1.len!=op2.len)
    {throw Error('+', op1.len, op2.len);}
    else {Vec<V> tmp(op1.len);
        for (int i=0; i<op1.len;i++)
        { tmp.v[i] = op1.v[i] + op2.v[i];} return tmp;}
}

template<typename T>
Vec<T>& Vec<T>:: operator=(const Vec<T>& op)
{   if(this->len == op.len)
    { for (int i=0; i<len; i++)
            v[i] = op.v[i];}
    else{
        len = op.len;
        v = new T[len];
        for (int i =0; i<len; i++)
        { v[i]= op.v[i];}}
    return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator += (const Vec<T>& op){
    if (len!=op.len){throw Error('+', op.len, this->len);}
    else{ for (int i=0; i<len; i++)
        {v[i]=v[i]+op.v[i];}}
    return *this;
}

template<typename V>
const V operator ^(const Vec<V>& op1, const Vec<V>& op2){
    V op=0;
    if(op1.len!=op2.len){throw Error('*', op1.len, op2.len);}
    else{ for(int i=0;i<op1.len;i++){
            op=op1.v[i]*op2.v[i]+op;}}
    return op;
}
template<typename V>
bool operator ==(const Vec<V>& op1, const Vec<V>&op2){
    if(op1.len!=op2.len){
        if(op1.len<op2.len){ int i=0;
            for(int i=0;i<op1.len;i++){
                if(op1.v[i]!=op2.v[i]){ return false; }}
            for(i=i;i<op2.len;i++){
                if(op2.v[i]!=0){return false;  } } }
        else{int i=0;
            for(i=0;i<op2.len;i++){
                if(op1.v[i]!=op2.v[i]){ return false; }}
            for(i=i;i<op1.len;i++){
                if(op1.v[i]!=0){return false; } } }}
    else{
        for(int i=0;i<op1.len;i++){
            if((op1.v[i])!=op2.v[i]){ return false; }} }
    return true;}

template<typename T>
Vec<T>::Vec(int len, T *array)
{
    if (len < 0){ throw "Exception: length error";}
    this->len = len;
    this->v = new T[len];
    for (int i =0; i<len; i++)
    {this->v[i] = array[i];}
}
template<typename T>
Vec<T>::Vec(T *array,int len)
{
    if (len < 0){ throw "Exception: length error";}
    this->len = len;
    this->v = new T[len];
    for (int i =0; i<len; i++)
    {this->v[i] = array[i];}
}

template<typename T>
Vec<T>::Vec(int len)
{
    if (len <0){ throw "Exception: length error";}
    this->len = len;
    this->v=new T[len];
    for (int i =0; i<len; i++)
    {this->v[i] = 0;}
}

template<typename T>
Vec<T>::Vec(const Vec<T> &coord)
{
    this->len = coord.len;
    this->v = new T[this->len];
    for (int i =0; i<coord.len; i++)
    {v[i]= coord.v[i];}
}

template<typename T>
void Vec<T>::set (T arg, int coord)
{
    if (coord>len || coord<0){ throw "Exception: coordinate error in set()";}
    v[coord]=arg;

}


/*void Vec::print()
{
    if (len==0){}
    else {cout<<"(";
    for(int i=0; i<this->len;i++)
    { cout<<this->v[i];
    if (i+1<this->len)
    { cout<<",";}
    else{ cout<<")"<<endl; }
}}}*/


template<typename T>
T Vec<T>::get(int coord){
    if(coord>=0&&coord<this->len)
    { return this->v[coord]; }
    else  { throw "Exception: coordinate error in get()";}
}
template<typename T>
T Vec<T>::euc_norm()
{
    T norm =0;
    for (int i=0; i<this->len; i++)
    {norm = norm + v[i]*v[i];}
    return sqrt(norm);
}

template<typename T>
T Vec<T>::max_norm()const{
    if (this->len == 0) return 0;
    else {T n =0;
        for (int i=0; i<this->len; i++)
        {if (abs(v[i])>n) n = abs(v[i]);}
        return n; }
}

template<typename V>
ostream& operator<<(ostream& os, const Vec<V>& op){
    os << "(";
    for (int i = 0;i < (op.len);i++){
        if (op.len-1==i) {os << op.v[i]; }
        else{ os << op.v[i]<< ",";}}
    os << ")";
    return os;
}

void Vector()
{
    int w1[3] = {1,2,3};
    int w2[3] = {2,3,1};
    Vec <int> v1(3, w1), v2(3, w2), v3(0);
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    v3 = 2*v1 + v2*3;
    cout << "v3 = " <<v3 << endl;
    int pr = v1^v2;
    cout << "v1^v2 = " << pr << endl;
    v1[1] = 7;
    cout << "v[1] = " << v1[1] << endl;
    v1=v2;
    if(v1==v2){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}


int main()
{
    try{Vector();}
    catch(Error &Err){
        if (Err.get_sym()=='+') {
            cerr<<"Exception: addition of vectors of different lengths: "<<Err.get_j()<<' '<<Err.get_i()<<endl;
            return 1;}
        else if (Err.get_sym()=='i'){
            cerr<<"Exception: incorrect indexing: "<<Err.get_i()<<endl;
            return 1;}
        else if (Err.get_sym()=='*'){
            cerr<<"Exception: multiplication of vectors of different lengths: "<<Err.get_j()<<' '<<Err.get_i()<<endl;
            return 1;}}
    catch(const char * err){
        cerr << err << endl;
        return 1;}
    catch(...){
        cerr << "Exception: unknown error" << endl;
        return 1;}
    return 0;
}