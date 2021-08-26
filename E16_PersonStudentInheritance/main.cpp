/**********************************************************************************
 *                          Наследование
 *********************************************************************************/

#include <iostream>

using namespace std;

class Person {
private:
    string firstName;
    string lastName;
protected:
    int age;
public:
    Person(const string &fn, const string &ln, int ag) {
        firstName = fn;
        lastName = ln;
        age = ag;
        //cout << " Person_constr ";
    }

    virtual void Print() const;

    void Change_age(int new_age) { age = new_age; }

    virtual ~Person() {             //if we use virtual methods, then we have to use virtual destructors
        //cout << " Person_destr ";
    }
};

void Person::Print() const {
    cout << "Name: " << firstName;
    cout << " LName: " << lastName;
    cout << " Age: " << age << endl;
}

class Student : public Person {
private:
    double grade;
public:
    Student(const string &fn, const string &ln, int ag, double gr) : Person(fn, ln, ag) {
        grade = gr;
        //cout << " Student_constr ";
    }

    virtual void Print() const;     // выбирать функцию по типу

    bool Bonus() const;

    void Change_grade(double new_gr) { grade = new_gr; }

    virtual ~Student() {
        //cout << " Student_destr ";
    }
};

bool Student::Bonus() const {
    if (age >= 18 && grade >= 4.5)
        return true;
    else
        return false;
}

void Student::Print() const {
    Person::Print();
    cout << "Grade: " << grade << endl;
}

/*void func(Person &pers) {
    ;
}*/

/*
int main() {
    //Сделать массив указателей на студентов и преподавателей
    const int NMAX = 5;
    Person *P[NMAX];
    for (int i = 0; i < NMAX; i++) {
        if (i % 2) // для нечетных
            P[i] = new Person("PN", "PF", i + 20);
        else   //для четных
            P[i] = new Student("SN", "SF", i + 15, i * 1.2);
    }
    cout << endl;

    for (int i = 0; i < NMAX; i++) {
        P[i]->Print();
    }

    for(int i =0; i<NMAX; i++)
    {
        delete P[i];
    }

    Person pers("A", "B", 23);
    pers.Print();       //Person::Print()

    Student stud("V", "E", 18, 4.7);
    stud.Print();
    stud.Bonus();
    stud.Change_age(19);
    stud.Change_grade(4.8);
    stud.Print();       //Student::Print()
    //stud.Print_Person();

    Person &pers1 = stud;       //неявное восходящее приведение типов
    Person *pers2 = &stud;

    pers1.Print();          //Person.Print()
    pers2->Print();         //Person.Print();

    func(pers);
    func(stud);


    return 0;
}*/