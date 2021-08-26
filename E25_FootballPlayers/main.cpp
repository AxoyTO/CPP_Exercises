#include <iostream>
#include <vector>

using namespace std;

//void clearVec(vector<int> a) {
//    a.clear();
//}

class Exception {
private:
    string comment;
    string teamName;
public:
    Exception(string arg_comment, string arg_teamName) : comment(arg_comment), teamName(arg_teamName) {}

    Exception(const Exception &other) {
        comment = other.comment;
        teamName = other.teamName;
    }

    string GetComment() const { return comment; }

    string GetTeamName() const { return teamName; }

    ~Exception() {}
};

class numErrException : public Exception {
private:
    int num;
public:
    numErrException(int arg_num, string arg_comment, string arg_teamName) : Exception(arg_comment,
                                                                                      arg_teamName) { num = arg_num; }

    numErrException(const numErrException &other) : Exception(other) { num = other.num; }

    int GetNum() const { return num; }

    ~numErrException() {}
};


class Player {
private:
    int playerNumber;
    string team;
    static vector<int> playersOfZenit;
    static vector<int> playersOfCSKA;
    static int playerCountZenit, playerCountCSKA;
    //static int playerCount;
public:
    Player(string arg_team, int arg_playerNumber) {
        /*if (playerCount == 0) {
            playersOfZenit.clear();
            playersOfCSKA.clear();
        }*/
        //playerCount++;
        team = arg_team;
        playerNumber = arg_playerNumber;

        if (playerNumber < 1) {
            //playersOfZenit.clear();
            //playersOfCSKA.clear();
            throw numErrException(playerNumber, "Exception: Wrong number in team ", team);
        }

        if (team == "Zenit") {
            playersOfZenit.push_back(playerNumber);
            for (int i = 0; i < playersOfZenit.size() - 1; i++) {
                if (playersOfZenit.at(i) == playersOfZenit.at(playerCountZenit)) {
                    //playersOfZenit.clear();
                    //playersOfCSKA.clear();
                    throw numErrException(playerNumber, "Exception: Double number in team ", team);
                }
            }
            playerCountZenit++;
        } else if (team == "CSKA") {
            playersOfCSKA.push_back(playerNumber);
            for (int i = 0; i < playersOfCSKA.size() - 1; i++) {
                if (playersOfCSKA[i] == playersOfCSKA[playerCountCSKA]) {
                    //playersOfZenit.clear();
                    //playersOfCSKA.clear();
                    throw numErrException(playerNumber, "Exception: Double number in team ", team);
                }
            }
            playerCountCSKA++;
        } else {
            //playersOfZenit.clear();
            //playersOfCSKA.clear();
            throw Exception("Exception: Wrong name in team ", team);
        }

        if (playerCountCSKA > 11) {
            //playersOfZenit.clear();
            //playersOfCSKA.clear();
            throw Exception("Exception: Too many players in team ", team);
        }

        if (playerCountZenit > 11) {
            //playersOfZenit.clear();
            //playersOfCSKA.clear();
            throw Exception("Exception: Too many players in team ", team);
        }
    }

    void Print() const {
        cout << team << " " << playerNumber << endl;
    }

    static void Print_teams() {
        //playersOfCSKA.shrink_to_fit();
        //playersOfZenit.shrink_to_fit();

        if (!playersOfZenit.empty()) {
            cout << "Zenit: ";
            for (int i = 0; i < playersOfZenit.size(); i++) {
                if (i == playersOfZenit.size() - 1)
                    cout << playersOfZenit.at(i);
                else
                    cout << playersOfZenit.at(i) << " ";
            }
            cout << endl;
        }
        if (!playersOfCSKA.empty()) {
            cout << "CSKA: ";
            for (int i = 0; i < playersOfCSKA.size(); i++) {
                if (i == playersOfCSKA.size() - 1)
                    cout << playersOfCSKA.at(i);
                else
                    cout << playersOfCSKA.at(i) << " ";
            }
            cout << endl;
        }
    }

    ~Player() {
        //cout << "Player Count of CSKA = " << playerCountCSKA << endl;
        //cout << "Player Count of Zenit = " << playerCountZenit << endl;

        if (team == "Zenit") {
            playerCountZenit--;
            //cout << "ZENIT PLAYER: " << playerCountZenit << endl;
            for (int i = 0; i < playersOfZenit.size(); i++) {
                if (playerNumber == playersOfZenit.at(i)) {
                    //cout << "Zenit " << playerNumber << endl;
                    playersOfZenit.erase(playersOfZenit.begin() + i);
                    break;
                }
            }
        } else if (team == "CSKA") {
            playerCountCSKA--;
            //cout << "CSKA PLAYER: " << playerCountCSKA << endl;
            for (int i = 0; i < playersOfCSKA.size(); i++) {
                if (playerNumber == playersOfCSKA.at(i)) {
                    //cout << "CSKA " << playerNumber << endl;
                    playersOfCSKA.erase(playersOfCSKA.begin() + i);
                    break;
                }
            }

            //cout << "Player Count = " << playerCount << endl;
            /*if (playerCountCSKA == 0) {
                for (int i = 0; i < playersOfCSKA.size(); i++) {
                    cout << playersOfCSKA.at(i) << " ";
                }
                cout << endl;
            }*/

        }/*
        if(playerCountCSKA == 0)
            for(int i = 0; i< playersOfCSKA.size(); i++)
                cout << playersOfCSKA.at(i) << " ";
        if (playerCountZenit == 0)
            for (int i = 0; i < playersOfZenit.size(); i++) {
                cout << playersOfZenit.at(i) << " ";
            }
        */
    }
};

//int Player::playerCount = 0;
int Player::playerCountCSKA = 0;
int Player::playerCountZenit = 0;
vector<int> Player::playersOfZenit;
vector<int> Player::playersOfCSKA;


/*void Players()
{
    Player pl1("Zenit", 10);
    Player pl2("Zenit", 11);
    Player pl3("CSKA", 23);
    Player pl4("CSKA", 10);
    Player pl5("Zenit", 4);
    Player pl6("Zenit", 1);
    Player pl7("CSKA", 7);
    Player pl8("Zenit", 4);

    pl1.Print();
    pl3.Print();
    Player::Print_teams();
}*/

int main() {
    try {
        Players();
    } catch (numErrException &ex) {
        cerr << ex.GetComment() << ex.GetTeamName() << " Error number: " << ex.GetNum() << endl;
    } catch (Exception &ex) {
        cerr << ex.GetComment() << ex.GetTeamName() << endl;
    }
    return 0;
}