//tried using namespace std manually

void print(int a)
{
    std::cout << "type: int " << "value: " << a << std::endl;
}

void print(double var)
{
    std::cout << "type: double " << "value: " << var << std::endl;
}

void print(const char *str)
{
    std::cout << "type: c-string " << "value: " << str << std::endl;
}

void print(int a, long b)
{
    std::cout << "type: int long " << "value: " << a << " " << b << std::endl;
}