/**********************************************************************************
 *                          Наследование
 *********************************************************************************/

#include <iostream>
#include <typeinfo>

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


int main() {
    /*Person pers("A", "B", 23);
    Student stud("V", "E", 18, 4.7);
    Person &pers1 = stud;       //неявное восходящее приведение типов
    Person *pers2 = &stud;

    //static_cast
    Student *stud2 = static_cast<Student*>(pers2);     //Низходящее приведение типов
    Student &stud1 = static_cast<Student&>(pers1);
    Student *stud3 = static_cast<Student*>(&pers);   //error

    stud3->Change_grade(3.14);
*/
    const int NMAX = 5;
    Person *P1 = new Person("PN", "PF", 20);
    Person *P2 = new Student("SN", "SF", 15, 1.2);

    Student *stud2;
    //dynamic_cast
    if (stud2 = dynamic_cast<Student *>(P2))
        stud2->Print();
    else
        cerr << "ERROR" << endl;

    if (stud2 = dynamic_cast<Student *>(P1))
        stud2->Print();
    else
        cerr << "ERROR" << endl;

    Person pers("A", "V", 45);
    Student stud("E", "Y", 18, 4.5);

    Person &pers1 = stud;
    try {
        Student &stud1 = dynamic_cast<Student &>(*P2);
        stud1.Print();
        Student &stud2 = dynamic_cast<Student &>(*P1);
        stud2.Print();
    }
    catch (bad_cast) {
        cerr << "ERROR 2" << endl;
    }

    delete P1;
    delete P2;
    return 0;
}