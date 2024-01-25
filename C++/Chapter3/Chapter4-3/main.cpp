#include <iostream>
using namespace std;

class Person{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage){
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    ~Person(){
        delete []name;
        cout << "called destructor!" << endl;
    }
};

int main() {
    Rectangle rec(1,1,5,5);
    rec.ShowRefInfo();
    return 0;
}
