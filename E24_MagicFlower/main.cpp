#include <iostream>

using namespace std;

class Flower {
private:
    string color;
    int amount;
    static int statWhite, statPink;
public:
    Flower(string arg_color, int arg_amount = 10) {
        color = arg_color;
        amount = arg_amount;
        //cout << "CONSTRUCTOR 2 PARAMS --- " << "COLOR = " << color << " LEAF = " << amount << endl;
        //cout << "Constructor" << endl;
        if (color == "white") {
            statWhite++;
        } else if (color == "pink") {
            statPink++;
        } else {
            if (statWhite < statPink) {
                //cout << "Debug ---- Color = " << color << endl;
                //cout << "Debug ---- StatWhite = " << statWhite << endl;
                //cout << "Debug ---- StatPink = " << statPink << endl;
                color = "white";
                statWhite++;
            } else if (statWhite == statPink) {
                //cout << "Debug ---- Color = " << color << endl;
                //cout << "Debug ---- StatWhite = " << statWhite << endl;
                //cout << "Debug ---- StatPink = " << statPink << endl;
                if (amount % 2) {
                    //cout << "amount%2=1 COLOR HERE IS " << color << endl;
                    //Flower("white");
                    color = "white";
                    statWhite++;
                } else {
                    //cout << "amount%2=0 COLOR HERE IS " << color << endl;
                    //Flower("pink");
                    color = "pink";
                    statPink++;
                }
            } else {
                //cout << "Debug ---- Color = " << color << endl;
                //cout << "Debug ---- StatWhite = " << statWhite << endl;
                //cout << "Debug ---- StatPink = " << statPink << endl;
                color = "pink";
                statPink++;
            }
        }
    }

    /*Flower(const Flower &other) {
        cout << "COPY CONSTRUCTOR" << endl;
        color = other.color;
        amount = other.amount;
        if (color == "white") {
            cout << "DEBUG IN COPY CONSTRUCTOR" << endl;
            statWhite++;
        } else
            statPink++;
    }*/

    Flower() {
        amount = 10;
        //cout << "DEFAULT CONSTRUCTOR --- " << "COLOR = " << color << " LEAF = " << amount << endl;
        if (statWhite < statPink) {
            //cout << "Debug ---- Color = " << color << endl;
            //cout << "Debug ---- StatWhite = " << statWhite << endl;
            //cout << "Debug ---- StatPink = " << statPink << endl;
            color = "white";
            statWhite++;
        } else if (statWhite == statPink) {
            //cout << "Debug ---- Color = " << color << endl;
            //cout << "Debug ---- StatWhite = " << statWhite << endl;
            //cout << "Debug ---- StatPink = " << statPink << endl;
            if (amount % 2) {
                color = "white";
                statWhite++;
            } else {
                color = "pink";
                statPink++;
            }
        } else {
            //cout << "Debug ---- Color = " << color << endl;
            //cout << "Debug ---- StatWhite = " << statWhite << endl;
            //cout << "Debug ---- StatPink = " << statPink << endl;
            color = "pink";
            statPink++;
        }
    }

    static void Print_flowers() {
        cout << "White: " << statWhite << " Pink: " << statPink << endl;
    }

    /*static void printStatWhite() {
        cout << statWhite;
    }

    static void printStatPink() {
        cout << statPink;
    }*/

    ~Flower() {
        //cout << "DESTRUCTOR --- " << "COLOR = " << color << " LEAF = " << amount << endl;
        if (color == "white")
            statWhite--;
        else if (color == "pink")
            statPink--;
        //Print_flowers();
    }
};

int Flower::statPink = 0;
int Flower::statWhite = 0;
/*
int main() {
    Flower fl1("white", 3);
    Flower fl2("white", 5);
    Flower fl3("white", 7);
    Flower::Print_flowers();
    Flower fl4("pink");
    Flower::Print_flowers();
    Flower fl5("blue", 17);
    Flower::Print_flowers();
    Flower fl6;
    Flower::Print_flowers();
    Flower fl7;
    Flower::Print_flowers();
    //fl7.printStatWhite();
    //fl7.printStatPink();
    return 0;
}*/