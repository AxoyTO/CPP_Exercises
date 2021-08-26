/******************************************************
 *                  Расписание сессии                 *
 *****************************************************/
/*
#include <iostream>

using namespace std;
*/
class event {
private:
    int year, month, day;
    string subject;
public:
    event(const string &s, int y, int m, int d) {
        year = y;
        month = m;
        day = d;
        subject = s;
    }

    virtual void print_res() const {
        cout << subject << " " << year << " " << month << " " << day << " ";
    }

    void change_date(int new_year, int new_month, int new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }

    virtual void change_grade(int) {}
    virtual void change_grade(bool) {}

    virtual ~event() {}
};

class test : public event {
private:
    bool zachet;
public:
    test(const string &s, int y, int m, int d, bool b) : event(s, y, m, d) {
        zachet = b;
    }

    virtual void print_res() const {
        event::print_res();
        cout << (zachet? "true" : "false") << endl;
    }

    virtual void change_grade(bool new_b) {
        zachet = new_b;
    }

    virtual ~test() {}
};

class exam : public event {
private:
    int grade;
public:
    exam(const string &s, int y, int m, int d, int g) : event(s, y, m, d) {
        grade = g;
    }

    virtual void print_res() const {
        event::print_res();
        cout << "Grade " << grade << endl;
    }

    virtual void change_grade(int new_g) {
        grade = new_g;
    }
};
/*
int main() {
    const int NUM = 7;
    event *session[NUM];

    session[0] = new test("MS Office", 2020, 12, 23, true);
    session[1] = new exam("Operation System", 2021, 1, 15, 2);
    session[2] = new test("Practicum", 2020, 12, 25, false);
    session[3] = new exam("Differential equation", 2021, 1, 20, 3);
    session[4] = new test("Theory of probability", 2020, 12, 29, true);
    session[5] = new exam("Philosophy", 2021, 1, 24, 5);
    session[6] = new exam("C++", 2021, 1, 11, 4);

    for (int i = 0; i < NUM; i++)
        session[i]->print_res();

    session[2]->change_date(2021, 2, 24);
    session[2]->change_grade(true);

    session[1]->change_date(2021, 2, 13);
    session[1]->change_grade(3);

    cout << endl;
    for (int i = 0; i < NUM; i++)
        session[i]->print_res();

    for (int i = 0; i < NUM; i++)
        delete session[i];
    return 0;
}*/