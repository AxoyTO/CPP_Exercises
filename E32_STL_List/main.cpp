#include <iostream>
#include <cstdio>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

bool isThere(list<int> &liste, long num, list<int>::iterator &it) {
    int flag = 0;
    int index = 0;
    for (it = liste.begin(); it != liste.end(); it++) {
        if (*it == num) {
            flag++;
            break;
        }
        index++;
    }
    if (flag)
        return true;
    else
        return false;
}

void Show(const int ptr) {
    cout << ptr << " ";
}

void findMax(list<int> &liste, int &max, list<int>::iterator &it) {
    for (it = liste.begin(); it != liste.end(); it++) {
        if (it == liste.begin())
            max = *it;
        else {
            if (*it > max)
                max = *it;
        }
    }

    for (it = liste.begin(); it != liste.end(); it++) {
        if (*it == max)
            break;
    }
}

int main(int argc, char **argv) {

    list<int> liste;
    auto it = liste.begin();
    int num;
    while (cin >> num) {
        liste.push_back(num);
    }

    if (argc < 2) {
        for_each(liste.begin(), liste.end(), Show);
        cout << endl;
        return 0;
    } else {
        string command;
        command = argv[1];

        if (command == "-af") {
            if (argc == 3) {
                char *ptr;
                liste.push_front(strtol(argv[2], &ptr, 10));
            }
        } else if (command == "-ae") {
            if (argc == 3) {
                char *ptr;
                liste.push_back(strtol(argv[2], &ptr, 10));
            }
        } else if (command == "-ib") {
            if (argc == 4) {
                char *ptr;
                if (isThere(liste, strtol(argv[3], &ptr, 10), it)) {
                    liste.insert(it, strtol(argv[2], &ptr, 10));
                }
            }
        } else if (command == "-ia") {
            if (argc == 4) {
                char *ptr;
                if (isThere(liste, strtol(argv[3], &ptr, 10), it)) {
                    liste.insert(++it, strtol(argv[2], &ptr, 10));
                }
            }

        } else if (command == "-d") {
            if (argc == 3) {
                char *ptr;
                if (isThere(liste, strtol(argv[2], &ptr, 10), it)) {
                    liste.erase(it);
                }
            }
        } else if (command == "-sa") {
            liste.sort();
        } else if (command == "-sd") {
            liste.sort();
            liste.reverse();
        } else if (command == "-mf") {
            if (!liste.empty()) {
                int max;
                findMax(liste, max, it);
                liste.erase(it);
                liste.push_front(max);
            }
        } else if (command == "-me") {
            if (!liste.empty()) {
                int min;
                findMax(liste, min, it);
                liste.erase(it);
                liste.push_back(min);
            }
        } else {
            for_each(liste.begin(), liste.end(), Show);
            cout << endl;
            return 0;
        }
    }
    for_each(liste.begin(), liste.end(), Show);
    cout << endl;
    return 0;
}
