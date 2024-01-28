#include <iostream>
using namespace std;

class First {
public:
    void FirstFunc() {cout << "FirstFunc()" << endl;}
    virtual void Simple() {cout << "First's SimpleFunc()" << endl;}
};

class Second : public First{
public:
    void SecondFunc() {cout << "SecondFunc()" << endl;}
    virtual void Simple() {cout << "Second's SimpleFunc()" << endl;}
};

class Third : public Second{
public:
    void ThirdFunc() {cout << "ThirdFunc()" << endl;}
    virtual void Simple() {cout << "Third's SimpleFunc()" << endl;}
};

int main() {
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.Simple(); // Third's SimpleFunc()

    Second & sref = obj;
    sref.SecondFunc();
    sref.FirstFunc();
    sref.Simple(); // Second's SimpleFunc()

    First & fref = sref;
    fref.FirstFunc();
    sref.Simple(); // First's SimpleFunc()
    return 0;
}
