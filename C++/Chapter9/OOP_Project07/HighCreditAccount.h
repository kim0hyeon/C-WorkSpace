//
// Created by 김영현 on 1/28/24.
//

#ifndef OOP_PROJECT07_HIGHCREDITACCOUNT_H
#define OOP_PROJECT07_HIGHCREDITACCOUNT_H

/*
 * 클래스 이름: HighCreditAccount
 * 클래스 유형: Entity 클래스
 * */

#include "Account.h"

class HighCreditAccount : public Account{
private:
    int rate;
    int credit;
public:
    HighCreditAccount(int ID, int money, char * name, int myRate, int myCredit);
    void Deposit(int money);
};

HighCreditAccount::HighCreditAccount(int ID, int money, char *name, int myRate, int myCredit)
        : Account(ID, money, name), rate(myRate), credit(myCredit){ }

void HighCreditAccount::Deposit(int money) {
    switch (credit){
        case 1:
            rate += 7;
            break;
        case 2:
            rate += 4;
            break;
        case 3:
            rate += 2;
            break;
    }
    balance += (int)(money * (1+rate*0.01));
}

#endif //OOP_PROJECT07_HIGHCREDITACCOUNT_H
