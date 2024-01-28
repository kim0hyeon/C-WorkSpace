#include <iostream>
#include <cstring>
using namespace std;

enum RISK_LEVEL{RISK_A = 1, RISK_B, RISK_C};

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
    virtual int GetPay() const{
        return 0;
    }
    virtual void ShowSalaryInfo() const { }
};

class TemporaryWorker : public Employee{ // 기간직은 정규직이 아닌 직원이기 때문에 직원을 상속받는다.
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

class PermanentWorker : public Employee{ // 영구직은 직원이기때문에 직원 클래스를 상속받는다.
private:
    int salary; // 매달 지불해야 하는 금여액
public:
    PermanentWorker(char * name, int money) : Employee(name), salary(money){
    }
    int GetPay() const{ return salary; }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class SalesWorker : public PermanentWorker{ // 영업사원은 정규직이기 때문에 정규직 클래스을 상속받는다.
private:
    int salesResult; // 월 판매실적
    double bonusRatio; // 상여금 비율
public:
    SalesWorker(char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio){}
    void AddSalesResult(int value){
        salesResult += value;
    }
    int GetPay() const{ // 가상함수로 바꿈으로서 ShowSalaryInfo함수를 삭제할 수 있게 되었다.
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
};

class ForeignSalesWorker : public SalesWorker {
private:
    int riskLevel;
public:
    ForeignSalesWorker(char * name, int money, double ratio, int level) : SalesWorker(name, money, ratio), riskLevel(level) {}
    int GetPay() const{
        switch(riskLevel){
            case 1:
                return (int)(SalesWorker::GetPay() * 1.3);
            case 2:
                return (int)(SalesWorker::GetPay() * 1.2);
            case 3:
                return (int)(SalesWorker::GetPay() * 1.1);
        }
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout << "salary: " << SalesWorker::GetPay() << endl;
        cout << "risk pay: " << GetPay() - SalesWorker::GetPay() << endl;
        cout << "sum: " << GetPay() << endl << endl;
    }
};

// 직원을 저장 및 관리하기 위한 클래스
class EmployeeHandler{
private:
    Employee * empList[50]; // 어떤 직원이 들어올지 모르니 일단 타입을 Employee로 설정
    int empNum;
public:
    EmployeeHandler() : empNum(0){  }
    void AddEmployee(Employee * emp){
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const{
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const{
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
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

    // 해외 영업직 등록
    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    // 이번달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    return 0;
}