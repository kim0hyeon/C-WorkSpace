#include <iostream>
using namespace std;

// 정규직 직원 클래스
class PermanetWorker{
private:
    char name[100];
    int salary; // 매달 지불해야 하는 금여액
public:
    PermanetWorker(char * name, int money) : salary(money){
        strcpy(this->name, name);
    }
    int GetPay() const{ return salary; }
    int ShowSalaryInfo() const{
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 직원을 저장 및 관리하기 위한 클래스
class EmployeeHandler{
private:
    PermanetWorker * empList[50];
    int empNum;
public:
    EmployeeHandler() : empNum(0){  }
    void AddEmployee(PermanetWorker * emp){
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
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanetWorker("KIM", 1000));
    handler.AddEmployee(new PermanetWorker("LEE", 1500));
    handler.AddEmployee(new PermanetWorker("JUN", 2000));

    // 이번달에 지불해야할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번달에 지불해야할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}
