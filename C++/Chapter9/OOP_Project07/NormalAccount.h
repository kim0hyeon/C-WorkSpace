//
// Created by 김영현 on 1/28/24.
//

#ifndef OOP_PROJECT07_NORMALACCOUNT_H
#define OOP_PROJECT07_NORMALACCOUNT_H

#include "Account.h"

/*
 * 클래스 이름: NormalAccount
 * 클래스 유형: Entity 클래스
 * */

class NormalAccount : public Account{
private:
    int rate;
public:
    NormalAccount(int ID, int money, char * name, int myRate);
    void Deposit(int money);
};

NormalAccount::NormalAccount(int ID, int money, char *name, int myRate)
        : Account(ID, money, name), rate(myRate) { }

void NormalAccount::Deposit(int money) {
    balance += (int)(money * (1+rate*0.01));
}

#endif //OOP_PROJECT07_NORMALACCOUNT_H
