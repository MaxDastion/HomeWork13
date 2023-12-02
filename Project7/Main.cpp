#include <iostream>

class FirstClass {
protected:
    int num;
public:
    FirstClass(int n) : num(n) {}
};

class SecondClass : public FirstClass {
public:
    std::string str;
    SecondClass(int n, std::string s) : FirstClass(n), str(s) {}
};

class ThirdClass : public SecondClass {
private:
    double dbl;
public:
    ThirdClass(int n, std::string s, double d) : SecondClass(n, s), dbl(d) {}
    friend void printData(const ThirdClass& obj);
};

void printData(const ThirdClass& obj) {
    std::cout << "Number: " << obj.num << std::endl;
    std::cout << "String: " << obj.str << std::endl;
    std::cout << "Double: " << obj.dbl << std::endl;
}


void main() {
    ThirdClass obj(12, "hello", 12.3);
    printData(obj);
}