#include <iostream>
#include <cstring>
using namespace std;

class Computer{
private:
    char owner[50];
public:
    Computer(char * name){
        strcpy(owner,name);
    }
    void Calculate(){
        cout << "요청 내용을 계산합ㄴ디ㅏ." << endl;
    }
};

class NotebookComp : public Computer{
private:
    int Battery;
public:
    NotebookComp(char * name, int initChag) : Computer(name), Battery(initChag) { }
    void Charging() { Battery += 5;}
    void useBattery() { Battery -= 1;}
    void MovingCal(){
        if (GetBatteryInfo() < 1){
            cout << "충전이 필요합니다." << endl;
            return ; // 이건 왜있는거?
        }
    }
    int GetBatteryInfo() const { return Battery; }
};

class TableNoteBook : public NotebookComp {
private:
    char regstPenModel[50];
public:
    TableNoteBook(char * name, int initChag, char * pen) : NotebookComp(name, initChag){
        strcpy(regstPenModel, pen);
    }
    void Write(char * penInfo){
        if (GetBatteryInfo() < 1){
            cout << "충전이 필요합니다." << endl;
            return ; // 이건 왜있는거야?
        }
        if (strcmp(regstPenModel, penInfo) != 0){
            cout << "등록된 펜이 아닙니다." << endl;
            return ; // 이건 왜있는거냐고
        }
        cout << "필기 내용을 처리합니다." << endl;
        useBattery();
    }
};

int main() {
    NotebookComp nc("이수종", 5);
    TableNoteBook tn("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}
