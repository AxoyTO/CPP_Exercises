/******************************************************************************
 *                         Исключения
 *           Подсчет количества символов в файле
 *****************************************************************************/

#include <iostream>     //input output stream
#include <fstream>      //file stream
#include <cstdio>       //c standart input output
#include <cstring>      //c string lib
#include <cerrno>       // ??

using namespace std;

class FileException {
private:
    char *filename;
    string comment;
    int err_code;

    char *strdup(const char *str);

public:
    FileException(const char *arg_file, const char *arg_comm);  //Конструктор с 2 параметрами
    FileException(const FileException &other);                  //Конструктор копирования   -- обязательно должен быть
    ~FileException();

    char *GetFilename() { return filename; }

    string GetComment() { return comment; }

    int GetErrCode() { return err_code; }

};

FileException::FileException(const char *arg_file, const char *arg_comm) {
    filename = strdup(arg_file);
    comment = arg_comm;
    err_code = errno;
}

FileException::~FileException() {
    delete[]filename;
}

FileException::FileException(const FileException &other) {
    filename = strdup(other.filename);
    comment = other.comment;
    err_code = other.err_code;
}

char *FileException::strdup(const char *str) {
    char *res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}


int count_symbols(char *filename) {
    int count = 0;
    ifstream fin(filename);     //на чтение открыть
    if (!fin.is_open())
        throw FileException(filename, "can't open file");       //Анонимный объект
    while (fin.get() != EOF)    //cin.get прочитать один символ
        count++;                //cin >> n          fin >> n
    fin.close();
    return count;

}


int main(int argc, char **argv) {
    if (argc < 2) {
        cerr << "No file name" << endl;     //stderr
    }
    int n;
    try {
        n = count_symbols(argv[1]);
        cout << "File " << argv[1] << " contains " << n << " symbols " << endl;
    }
    catch (FileException &ex) {         //ловим КОПИЮ объекта
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename();
        cerr << " Error code: " << strerror(ex.GetErrCode()) << endl;
        return 1;
    }


    ofstream fout("data.txt");      //На запись открыть
    if (!fout.is_open()) {
        cerr << "can't open file data.txt" <<
             endl;
        return 2;
    }

    fout << "File " << argv[1] << " contains " << n << " symbols " <<
         endl;
    fout.close();

    return 0;
}
