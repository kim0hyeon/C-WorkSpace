//
// Created by 김영현 on 1/28/24.
//
/*
 * 클래스 이름: Account
 * 클래스 유형: Base 클래스
 * */
#include "Account.h"
#include <iostream>
#include <cstring>
using namespace std;

Account::Account(int ID, int money, char *name) : accID(ID), balance(money){
    cusName = new char[strlen(name)+1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance){
    cusName = new char[strlen(ref.cusName)+1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

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