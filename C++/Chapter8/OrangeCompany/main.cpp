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
        cout << "salary: " << GetPay() << endl << endl;
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

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));

    // 임시직 등록
    TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
    alba->AddWorker(5);
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    // 이번달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}