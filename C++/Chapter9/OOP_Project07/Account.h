//
// Created by 김영현 on 1/28/24.
//

/*
 * 클래스 이름: Account
 * 클래스 유형: Base 클래스
 * */

#ifndef OOP_PROJECT07_ACCOUNT_H
#define OOP_PROJECT07_ACCOUNT_H


class Account{
private:
    int accID;
    char * cusName;
protected:
    int balance;
public:
    Account(int ID, int money, char * name);
    Account(const Account & ref);
    virtual void Deposit(int money) = 0;
    int GetAccID() const;
    int WithDraw(int money);
    void ShowAccInfo() const;
    ~Account();
};


#endif //OOP_PROJECT07_ACCOUNT_H
