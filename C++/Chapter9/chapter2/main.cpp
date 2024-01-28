#include <iostream>
using namespace std;

class Base{
public:
    Base() {
        cout << "Base Constructor" << endl;
    }
    void SimpleFunc() {
        cout << "BaseOne" << endl;
    }
};

class MiddleDerivedOne : virtual public Base{
public:
    MiddleDerivedOne() : Base(){
        cout << "MiddleDerivedOne Constructor" << endl;
    }
    void MiddleFuncOne(){
        SimpleFunc();
        cout << "MiddleDerivedOne" << endl;
    }
};

class MiddleDerivedTwo : virtual public Base{
public:
    MiddleDerivedTwo() : Base(){
        cout << "MiddleDerivedTwo Constructor" << endl;
    }
    void MiddleFuncTwo(){
        SimpleFunc();
        cout << "MiddleDerivedTwo" << endl;
    }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo{ // 중간 유도클래스 둘 다 Base 클래스를 상속받아서 마지막 유도클래스는 결국 Base클래스를 간접적으로 두 번 상속한다.
public:
    LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo(){
        cout << "LastDerived Constructor" << endl;
    }
    void ComplexFunc(){
        MiddleFuncOne();
        MiddleFuncTwo();
        SimpleFunc();
    }
};

int main(void){
    cout << "객체 생성 전... " << endl;
    LastDerived ldr;
    cout << "객체 생성 후..." << endl;
    ldr.ComplexFunc();
}