#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool isInt(char a) {
    if (a < 48 || a > 58)
        return false;
    else
        return true;
}

class Exception {
private:
    string comment;
public:
    Exception(string arg_com) : comment(arg_com) {}

    Exception(const Exception &other) { comment = other.comment; }

    string GetComment() {
        return comment;
    }

    ~Exception() {}
};

class NegCoordException : public Exception {
private:
    int coord;
public:
    NegCoordException(int arg_coord, string arg_comm) : Exception(arg_comm) {
        coord = arg_coord;
    }

    NegCoordException(const NegCoordException &other) : Exception(other) {
        coord = other.coord;
    }

    int GetCoord() const {
        return coord;
    }

    ~NegCoordException() {}
};


class Vector_2d {
private:
    int x, y;
public:
    Vector_2d() : x(0), y(0) {}

    Vector_2d(int p_arg1, int p_arg2) : x(p_arg1), y(p_arg2) {}

    friend ostream &operator<<(ostream &os, const Vector_2d &other) {
        os << "(" << other.x << "," << other.y << ")" << endl;
        return os;
    }

    friend istream &operator>>(istream &is, Vector_2d &other) {
        //is >> other.x >> other.y;
        int count = 0, indexFF = -1, indexFL = -1, indexLF = -1, indexLL = -1, combo = 1, n1 = 0, n2 = 0; //FirstLast - LastFirst
        int nullFlag = 0, k = 0;
        bool neg;
        vector<char> vec;
        char c;
        while (true) {
            c = getchar();
            if ((c == '\n' || c == EOF) && k == 0) {
                nullFlag = 1;
                break;
            }
            vec.push_back(c);
            k++;
            if (c == '\n' || c == EOF) {
                vec.push_back('\n');
                break;
            }
        }

        //cout << "nullFlag = " << nullFlag << endl;
        if (nullFlag == 0) {
            for (int i = 0; i < vec.size(); i++) {
                if (isInt(vec.at(i)) && indexFF == -1)
                    indexFF = i;
                if (isInt(vec.at(i)) && indexFL != -1 && indexLF == -1) {
                    indexLF = i;
                }
                if (isInt(vec.at(i)) && !isInt(vec.at(i + 1))) {
                    //cout << vec.at(i);
                    if (count == 0) {
                        indexFL = i;
                    } else
                        indexLL = i;
                    count++;
                } else if (vec.at(i) == '\n' || count == 2) {
                    break;
                }
            }
            //cout << endl << "indexFF=" << indexFF << "indexFL=" << indexFL << " indexLF=" << indexLF << " indexLL=" << indexLL << endl;
            if (count == 1) {
                throw Exception("Exception: one coordinate");
            }

            for (int i = indexFF; i < indexFL + 1; i++) {
                for (int j = indexFL; j > i; j--) {
                    combo *= 10;
                }
                //cout << "vec.at(i) = " << vec.at(i) - 48 << endl;
                //cout << "combo = " << combo << endl;
                //cout << "vec.at(i) * combo = " << (vec.at(i) - 48) * combo << endl;
                n1 += (vec.at(i) - 48) * combo;
                combo = 1;
                //cout << "n1 = " << n1 << endl;
            }
            if (indexFF != 0) {
                if (vec.at(indexFF - 1) == '-')
                    other.x = -n1;
                else
                    other.x = n1;
            } else
                other.x = n1;
            combo = 1;

            vec.at(indexLF - 1) == '-' ? neg = true : neg = false;
            //cout << neg;
            if (!neg)
                for (int i = indexLF; i < indexLL + 1; i++) {
                    for (int j = indexLL; j > i; j--) {
                        combo *= 10;
                    }
                    //cout << "vec.at(i) = " << vec.at(i) - 48 << endl;
                    //cout << "combo = " << combo << endl;
                    //cout << "vec.at(i) * combo = " << (vec.at(i) - 48) * combo << endl;
                    n2 += (vec.at(i) - 48) * combo;
                    combo = 1;
                    //cout << "n2 = " << n2 << endl;
                }
            else {
                for (int i = indexLF; i < indexLL + 1; i++) {
                    for (int j = indexLL; j > i; j--) {
                        combo *= 10;
                    }
                    //cout << "vec.at(i) = " << vec.at(i) - 48 << endl;
                    //cout << "combo = " << combo << endl;
                    //cout << "vec.at(i) * combo = " << (vec.at(i) - 48) * combo << endl;
                    n2 += (vec.at(i) - 48) * combo;
                    combo = 1;
                    //cout << "n2 = " << n2 << endl;
                }
            }
            if (neg)
                other.y = -n2;
            else
                other.y = n2;

            vec.clear();
            if (other.x < 0)
                throw NegCoordException(other.x, "Exception: negative coordinate:");
            else if (other.y < 0)
                throw NegCoordException(other.y, "Exception: negative coordinate:");
        }
        return is;
    }
};

int main() {
    try {
        Vector_2d v;
        cin >> v;
        cout << v << endl;
    }
    catch (NegCoordException &ex) {
        cerr << ex.GetComment() << ex.GetCoord() << endl;
    }
    catch (Exception &ex) {
        cerr << ex.GetComment() << endl;
    }

    return 0;
}