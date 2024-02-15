//
// Created by 김영현 on 1/28/24.
//

#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDec1.h"
#include <iostream>
using namespace std;



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
    int menu;
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: "; cin >> menu;

    switch(menu){
        case 1:
            MakeNormalAccount();
            break;
        case 2:
            MakeHighCreditAccount();
            break;
    }
}

void AccountHandler::MakeNormalAccount() {
    int id;
    char name[NAME_LEN];
    int balance;
    int rate;

    cout << "[보통예금계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> rate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, rate);
}

void AccountHandler::MakeHighCreditAccount() {
    int id;
    char name[NAME_LEN];
    int balance;
    int rate;
    int credit;

    cout << "[신용신뢰계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이 름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> rate;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> credit;
    cout << endl;

    accArr[accNum++] = new HighCreditAccount(id, balance, name, rate, credit);
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
