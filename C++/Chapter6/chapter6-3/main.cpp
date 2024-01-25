#include <iostream>
using namespace std;

class SoSimple{
private:
    int num1;
    mutable int num2;
public:
    SoSimple(int n1, int n2) : num1(n1), num2(n2) { }
    void ShowSimpleData() const{
        cout << num1 << ", " << num2 << endl;
    }
    void CozyToNum2() const{
        num2 = num1; // const 함수인데 함수 내부에서 변수값 변경이?!
    }
};