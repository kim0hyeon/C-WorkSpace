#include <iostream>
#include <cstring>
using namespace std;

class Employee{
private:
    char name[100];
public:
    Employee(char * name){
        strcpy(this->name, name);
    }
    void ShowYourName() const{
        cout << "name: " << name << endl;
    }
};

class TemporaryWorker : public Employee{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(char * name, int pay) : Employee(name), payPerHour(pay), workTime(0){ }
    void AddWorker(int time){
        workTime += time;
    }
    int GetPay() const{ // 이 달의 급여
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }


};

class PermanetWorker : public Employee{
private:
    int salary; // 매달 지불해야 하는 금여액
public:
    PermanetWorker(char * name, int money) : Employee(name), salary(money){
    }
    int GetPay() const{ return salary; }
    int ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

// 직원을 저장 및 관리하기 위한 클래스
class EmployeeHandler{
private:
    Employee * empList[50]; // 어떤 직원이 들어올지 모르니 일단 타입을 Employee로 설정
    int empNum;
public:
    EmployeeHandler() : empNum(0){  }
    void AddEmployee(PermanetWorker * emp){
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const{
//        for (int i = 0; i < empNum; i++)  과거 코드
//            empList[i]->ShowSalaryInfo(); 과거 코드

    }
    void ShowTotalSalary() const{
        int sum = 0;
//        for (int i = 0; i < empNum; i++)  과거 코드
//            sum += empList[i]->GetPay();  과거 코드
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler(){
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main() {
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanetWorker("KIM", 1000));
    handler.AddEmployee(new PermanetWorker("Lee", 1500));
    handler.AddEmployee(new PermanetWorker("JUN", 2000));

    // 이번달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}