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

//Иерархия Классов

class Exception {
    string comment;
public:
    Exception(const char *arg_com) : comment(arg_com) {}

    Exception(const Exception &other) { comment = other.comment; }

    ~Exception() {}

    string GetComment() const { return comment; }
};


class FileException : public Exception {
    char *filename;

    char *strdup(const char *str);

public:
    FileException(const char *arg_file, const char *arg_comm) : Exception(arg_comm) {
        filename = strdup(arg_file);
    }

    FileException(const FileException &other) : Exception(other) {
        filename = strdup(other.filename);
    }

    char *GetFilename() const { return filename; }

    ~FileException() { delete[]filename; }
};

char *FileException::strdup(const char *str) {
    char *res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}

class FileErrCodeException : public FileException {
    int err_code;
public:
    FileErrCodeException(const char *fn, const char *com) : FileException(fn, com) {
        err_code = errno;
    }

    FileErrCodeException(const FileErrCodeException &other) : FileException(other) {
        err_code = other.err_code;
    }

    int GetErrCode() const { return err_code; }
};


int count_symbols(char *filename) {
    int count = 0;
    ifstream fin(filename);     //на чтение открыть
    if (!fin.is_open())
        throw FileErrCodeException(filename, "can't open file"); //"can't open file" filename err_code
    while (fin.get() != EOF)    //cin.get прочитать один символ
        count++;                //cin >> n          fin >> n
    if (count == 0)
        throw FileException(filename, "is empty");  //"is empty" filename
    fin.close();
    return count;

}


int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw Exception("no filename");       //"No filename"
        int n;
        n = count_symbols(argv[1]);
        cout << "File " << argv[1] << " contains " << n << " symbols " << endl;
    }
    catch (FileErrCodeException &ex) {         //ловим КОПИЮ объекта -- Поймает объекты Exception, FileException and FileErrCodeException
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename();
        cerr << " Error code: " << strerror(ex.GetErrCode()) << endl;
        return 1;
    }
    catch (FileException &ex) {
        cerr << "Exception: " << ex.GetFilename() << " " << ex.GetComment() << endl;
        return 2;
    }
    catch (Exception &ex) {
        cerr << "Exception: " << ex.GetComment() << endl;
    }

    return 0;
}