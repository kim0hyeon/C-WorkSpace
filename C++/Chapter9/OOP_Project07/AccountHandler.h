//
// Created by 김영현 on 1/28/24.
//

#ifndef OOP_PROJECT07_ACCOUNTHANDLER_H
#define OOP_PROJECT07_ACCOUNTHANDLER_H

#include "Account.h"

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
    void MakeNormalAccount();
    void MakeHighCreditAccount();
    void DepositMoney();
    void WithDrawMoney();
    void ShowAllAccInfo() const;
    ~AccountHandler();
};


#endif //OOP_PROJECT07_ACCOUNTHANDLER_H
