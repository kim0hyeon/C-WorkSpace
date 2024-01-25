#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN =  20;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

/*
 * 클래스 이름: Account
 * 클래스 유형: Entity 클래스
 * */

class Account{
private:
    int accID;
    int balance;
    char * cusName;
public:
    Account(int ID, int money, char * name);
    Account(const Account & ref);

    int GetAccID() const;
    void Deposit(int money);
    int WithDraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

Account::Account(int ID, int money, char *name) : accID(ID), balance(money){
    cusName = new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance){
    cusName = new char[strlen(ref.cusName)+1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) { balance += money; }

int Account::WithDraw(int money) {
    if (money > balance)
        return 0;
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const {
    cout << "계좌ID: " << accID << endl;
    cout << "이 름: " << cusName << endl;
    cout << "잔 액: " << balance << endl;
}

Account::~Account() {
    delete []cusName;
}

/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: 컨트롤(control) 클래스
 * */

class AccountHandler{
private:
    Account * accArr[50];
    int accNum;
public:
    AccountHandler();
    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithDrawMoney();
    void ShowAllAccInfo() const;
    ~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu() const {
    cout << "-------Menu-------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount() {
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney() {
    int money;
    int id;
    cout << "[입   금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "입금액: "; cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "입금 완료" << endl << endl;
            return ; // 입금 완료했으니 함수 종료
        }
    }
    cout << "입금할 계좌id가 없습니다. 메뉴로 돌아갑니다." << endl << endl;
}

void AccountHandler::WithDrawMoney() {
    int money;
    int id;
    cout << "[출   금]" << endl;
    cout << "계좌 ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < accNum; i++){
        if (accArr[i]->GetAccID() == id){
            if(accArr[i]->WithDraw(money) == 0){
                cout << "잔액 부족" << endl << endl;
                return ;
            }
            cout << "출금 완료" << endl << endl;
            return ;
        }
    }
    cout << "출금할 계좌 id가 없습니다. 메뉴로 돌아갑니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const {
    for (int i = 0; i < accNum; i++) {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler() {
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}

/*
 * 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
 * */

int main() {
    AccountHandler manager;
    int choice;

    while(true){
        manager.ShowMenu();
        cout << "선택: "; cin >> choice;
        cout << endl;

        switch(choice){
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.DepositMoney();
                break;
            case WITHDRAW:
                manager.WithDrawMoney();
                break;
            case INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}
